/*
 * This file was generated by qofonodbusxml2cpp version 0.7
 * Command line was: qofonodbusxml2cpp -p qofonosimmanager ofono.xml org.ofono.SimManager
 *
 * qofonodbusxml2cpp is Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#include "qofonosimmanager.h"

/*
 * Implementation of interface class OrgOfonoSimManagerInterface
 */

OrgOfonoSimManagerInterface::OrgOfonoSimManagerInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
    : QOFonoDbusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
{
}

OrgOfonoSimManagerInterface::~OrgOfonoSimManagerInterface()
{
}

