/*
 * This file was generated by qfsodbusxml2cpp version 0.7
 * Command line was: qfsodbusxml2cpp -p qfsoresource -c QFsoResource specs/xml/org.freesmartphone.Resource.xml
 *
 * qfsodbusxml2cpp is Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef QFSORESOURCE_H
#define QFSORESOURCE_H

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
 * Proxy class for interface org.freesmartphone.Resource
 */
class QFSO_EXPORT QFsoResource: public QFsoDbusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freesmartphone.Resource"; }

public:
    QFsoResource(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~QFsoResource();

public Q_SLOTS: // METHODS
    inline QFsoDBusPendingReply<> Disable()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("Disable"), argumentList);
    }

    inline QFsoDBusPendingReply<> Enable()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("Enable"), argumentList);
    }

    inline QFsoDBusPendingReply<QVariantMap> GetDependencies()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("GetDependencies"), argumentList);
    }

    inline QFsoDBusPendingReply<> Resume()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("Resume"), argumentList);
    }

    inline QFsoDBusPendingReply<> Suspend()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("Suspend"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

namespace org {
  namespace freesmartphone {
    typedef ::QFsoResource Resource;
  }
}
#endif
