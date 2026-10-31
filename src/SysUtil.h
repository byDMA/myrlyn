/*  ---------------------------------------------------------
               __  __            _
              |  \/  |_   _ _ __| |_   _ _ __
              | |\/| | | | | '__| | | | | '_ \
              | |  | | |_| | |  | | |_| | | | |
              |_|  |_|\__, |_|  |_|\__, |_| |_|
                      |___/        |___/
    ---------------------------------------------------------

    Project:  Myrlyn Package Manager GUI
    Copyright (c) Stefan Hundhammer <Stefan.Hundhammer@gmx.de>
    License:  GPL V2 - See file LICENSE for details.

 */


#ifndef SysUtil_h
#define SysUtil_h


#include <QString>

class QProcess;
class QProcessEnvironment;


/**
 * System utility functions
 **/
namespace SysUtil
{
    /**
     * Open a URL in the desktop's default browser
     * (using the /usr/bin/xdg-open command).
     *
     * If running as root, this drops privileges first.
     * If that is not possible, this call will fail.
     **/
    void openInBrowser( const QString & url );

    /**
     * Check if an URL can safely be opened in the user's standard web browser:
     * Either if we are not running as root anyway, or if we are running as
     * root, but from a 'sudo' session so privileges can be dropped and the
     * environment set up for a normal user. This requires several environment
     * variables like SUDO_USER to be set.
     **/
    bool canOpenInBrowser();

    /**
     * Drop root privileges to the normal user in environment variables
     * SUDO_UID, SUDO_GID, SUDO_USER with SUDO_HOME and adapt the environment
     * accordingly.
     *
     * Return 'true' on success, 'false' on error.
     **/
    bool dropPrivileges( QProcess *            process,
                         QProcessEnvironment * env );

    /**
     * Return 'true' if this process can drop root privileges.
     * Currently, this is only possible if running with 'sudo'.
     *
     * This does not check if the process is running with root privileges;
     * check that first.
     **/
    bool canDropPrivileges();

    /**
     * Return 'true' if the 'xdg-open' command is available and executable.
     **/
    bool haveXdgOpenCommand();


    /**
     * Return 'true' if the specified command is available and executable.
     **/
    bool haveCommand( const QString & command );

    /**
     * Check if this program runs with root privileges, i.e. with effective
     * user ID 0.
     *
     * Notice that unlike MyrlynApp::runningAsRoot(), this does not take the
     * '--fake-root' command line argument into consideration; this is more
     * equivalent to MyrlynApp::runningAsRealRoot().
     **/
    bool runningAsRoot();

    /**
     * Check if this program runs with 'sudo'.
     **/
    bool runningWithSudo();
}


#endif // SysUtil_h
