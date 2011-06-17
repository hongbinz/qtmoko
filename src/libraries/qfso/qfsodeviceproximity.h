/*
 * This file was generated by qfsodbusxml2cpp version 0.7
 * Command line was: qfsodbusxml2cpp -p qfsodeviceproximity -c QFsoDeviceProximity specs/xml/org.freesmartphone.Device.Proximity.xml
 *
 * qfsodbusxml2cpp is Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef QFSODEVICEPROXIMITY_H
#define QFSODEVICEPROXIMITY_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include <qfsodbusabstractinterface.h>

#if defined(QFSO_LIBRARY)
    #define QFSO_EXPORT Q_DECL_EXPORT
#else
    #define QFSO_EXPORT Q_DECL_IMPORT
#endif

/*
 * Proxy class for interface org.freesmartphone.Device.Proximity
 */
class QFSO_EXPORT QFsoDeviceProximity: public QFsoDbusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freesmartphone.Device.Proximity"; }

public:
    QFsoDeviceProximity(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~QFsoDeviceProximity();

public Q_SLOTS: // METHODS
    inline QFsoDBusPendingReply<int, int> GetProximity()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("GetProximity"), argumentList);
    }
    inline QDBusReply<int> GetProximity(int &epoch)
    {
        QList<QVariant> argumentList;
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QLatin1String("GetProximity"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 2) {
            epoch = qdbus_cast<int>(reply.arguments().at(1));
        }
        return reply;
    }

Q_SIGNALS: // SIGNALS
    void Proximity(int proximity);
};

namespace org {
  namespace freesmartphone {
    namespace Device {
      typedef ::QFsoDeviceProximity Proximity;
    }
  }
}
#endif
