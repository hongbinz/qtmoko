/****************************************************************************
**
** This file is part of the Qt Extended Opensource Package.
**
** Copyright (C) 2011 Radek Polak.
**
** Contact: Qt Extended Information (info@qtextended.org)
**
** This file may be used under the terms of the GNU General Public License
** version 2.0 as published by the Free Software Foundation and appearing
** in the file LICENSE.GPL included in the packaging of this file.
**
** Please review the following information to ensure GNU General Public
** Licensing requirements will be met:
**     http://www.fsf.org/licensing/licenses/info/GPLv2.html.
**
**
****************************************************************************/

#include "ofonophonecall.h"
#include "ofonotelephonyservice.h"
#include "ofonocallprovider.h"

OFonoPhoneCall::OFonoPhoneCall
    (OFonoTelephonyService * service, const QString & identifier,
     const QString & callType, QString path)
:QPhoneCallImpl(&service->call_provider, identifier, callType)
, service(service)
, oVoiceCall("org.ofono", path, QDBusConnection::systemBus(), this)
{
}

OFonoPhoneCall::~OFonoPhoneCall()
{
}

static QPhoneCall::State ofonoStatusToQt(QString ofonoStatus, bool hangupLocal)
{
    if (ofonoStatus == "INCOMING")  // The call is incoming (but not yet accepted)
        return QPhoneCall::Incoming;
    if (ofonoStatus == "OUTGOING")  // The call is outgoing (but not yet established)
        return QPhoneCall::Dialing;
    if (ofonoStatus == "ACTIVE")    // The call is the active call (you can talk),
        return QPhoneCall::Connected;
    if (ofonoStatus == "HELD")  // The call is being held
        return QPhoneCall::Hold;
    if (ofonoStatus == "RELEASE")   // The call has been released
        return hangupLocal ? QPhoneCall::HangupLocal : QPhoneCall::HangupRemote;

    qWarning() << "ofonoStatusToQt: unknown status " << ofonoStatus;
    return QPhoneCall::OtherFailure;
}

void OFonoPhoneCall::setOFonoStatus(QString ofonoStatus)
{
    setState(ofonoStatusToQt(ofonoStatus, false));
}

void OFonoPhoneCall::dial(const QDialOptions & options)
{
    QString number = options.number();
    setNumber(number);

    qDebug() << "OFonoPhoneCall::dial(" << number << ")";

    QOFonoDBusPendingCall call = service->oVoiceCallManager.Dial(number, "");
    watchOFonoCall(call, this, SLOT(dialFinished(QOFonoDBusPendingCall &)));
    setState(QPhoneCall::Dialing);
}

void OFonoPhoneCall::dialFinished(QOFonoDBusPendingCall & call)
{
    QOFonoDBusPendingReply < QDBusObjectPath > reply = call;
    if (checkReply(reply)) {
        // Destruct old dbus interface and create new in the same place
        oVoiceCall.~OrgOfonoVoiceCallInterface();
        new(&oVoiceCall) OrgOfonoVoiceCallInterface("org.ofono",
                                                    reply.value().path(),
                                                    QDBusConnection::systemBus
                                                    (), this);
    }
}

void OFonoPhoneCall::hangup(QPhoneCall::Scope scope)
{
    qDebug() << "OFonoPhoneCall::hangup()";

    if (scope == QPhoneCall::CallOnly) {
        QOFonoDBusPendingReply <> reply = oVoiceCall.Hangup();
        checkReply(reply);
    } else {
        QOFonoDBusPendingReply <> reply =
            service->oVoiceCallManager.HangupAll();
        checkReply(reply);
    }
    setState(QPhoneCall::HangupLocal);
}

void OFonoPhoneCall::accept()
{
    qDebug() << "OFonoPhoneCall::accept()";
    QOFonoDBusPendingReply<> reply = oVoiceCall.Answer();
    checkReply(reply);
}

void OFonoPhoneCall::hold()
{
    qDebug() << "OFonoPhoneCall::hold()";
    QOFonoDBusPendingReply<> reply = service->oVoiceCallManager.HoldAndAnswer();
    checkReply(reply);
}

void OFonoPhoneCall::activate(QPhoneCall::Scope)
{
    qDebug() << "OFonoPhoneCall::activate()";
    QOFonoDBusPendingReply<> reply = service->oVoiceCallManager.ReleaseAndAnswer();
    checkReply(reply);
}

void OFonoPhoneCall::tone(const QString & tones)
{
    qDebug() << "OFonoPhoneCall::tone(" << tones << ")";
    QOFonoDBusPendingReply<> reply = service->oVoiceCallManager.SendTones(tones);
    checkReply(reply);    
}

void OFonoPhoneCall::transfer(const QString & number)
{
    qDebug() << "OFonoPhoneCall::transfer(" << number << ")";
    QOFonoDBusPendingReply<> reply = service->oVoiceCallManager.Transfer();
    checkReply(reply);
}