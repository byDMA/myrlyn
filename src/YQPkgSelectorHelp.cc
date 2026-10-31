/*  ---------------------------------------------------------
               __  __            _
              |  \/  |_   _ _ __| |_   _ _ __
              | |\/| | | | | '__| | | | | '_ \
              | |  | | |_| | |  | | |_| | | | |
              |_|  |_|\__, |_|  |_|\__, |_| |_|
                      |___/        |___/
    ---------------------------------------------------------

    Project:  Myrlyn Package Manager GUI
    Copyright (c) 2024-26 SUSE LLC
    License:  GPL V2 - See file LICENSE for details.

 */


#include <QString>

#include "Logger.h"
#include "utf8.h"
#include "ui_about-dialog.h"
#include "SysUtil.h"
#include "YQPkgSelector.h"

using SysUtil::openInBrowser;


void YQPkgSelector::help() const
{
    openInBrowser( "https://github.com/shundhammer/myrlyn/blob/master/README.md" );
}


void YQPkgSelector::helpRepoConfig() const
{
    openInBrowser( "https://github.com/shundhammer/myrlyn/issues/69" );
}


void YQPkgSelector::helpRootAuth() const
{
    openInBrowser( "https://github.com/shundhammer/myrlyn/issues/99" );
}


void YQPkgSelector::helpDevelopmentStatus() const
{
    openInBrowser( "https://github.com/shundhammer/myrlyn/issues/1" );
}


void YQPkgSelector::helpLatestRelease() const
{
    openInBrowser( "https://github.com/shundhammer/myrlyn/releases" );
}


void YQPkgSelector::about()
{
    QDialog aboutDialog( this );
    Ui::AboutDialog * ui( new Ui::AboutDialog );
    ui->setupUi( &aboutDialog );

    QString text = ui->heading->text();
    text += QString( " %1" ).arg( VERSION );
    ui->heading->setText( text );

    QStringList contributors = QStringList() << "\n"  // The "\n" is needed for the join()
        << fromUTF8( "@gruenich (Christoph Grüninger)" )
        << "@Arthurium-On-Linux"
        << "@byDMA"
        << "@slothsnow"
        << "@Sauerlandlinux (Stephan Hemeier)"
        ;
    ui->contributorsText->setText( contributors.join( "\n- " ) );;

    aboutDialog.exec();
    delete ui;
}

