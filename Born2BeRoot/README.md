*This project has been created as part of the 42 curriculum by adimas-d.*

# Born2BeRoot

## Description
Born2BeRoot is a system administration project where I built and secured a Linux server in a virtual machine.

This setup uses Debian stable with a security-first configuration:
- encrypted partitions with LVM,
- OpenSSH on port `4242` with root login disabled,
- active `ufw` firewall rules,
- strict password and `sudo` policies,
- and periodic system monitoring via a Bash script.

## Project Description
### Why Debian
I used Debian because it is stable, lightweight, highly documented, and very suitable for a minimal server architecture.

### Main Design Choices
- Partitioning: encrypted LVM layout with separated logical volumes to improve organization and security.
- Access policy: SSH allowed on `4242` only, no direct root SSH access.
- Firewall policy: `ufw` enabled at startup with only necessary ports open.
- User policy: user `adimas-d` belongs to `sudo` and `user42` groups.
- Password policy: expiration, minimum age, warning period, complexity, and username checks enforced.
- Sudo hardening: limited retries, custom failure message, TTY requirement, restricted secure path, and complete I/O logging in `/var/log/sudo/`.

### Mandatory Scope Implemented
- Debian minimal server (no graphical environment).
- AppArmor enabled at startup.
- SSH service configured and secured.
- `ufw` configured and active.
- `monitoring.sh` broadcasting system metrics at boot and every 10 minutes.

### Bonus Scope Implemented
- Advanced LVM partition structure configured.
- Functional WordPress stack installed (`lighttpd`, `MariaDB`, `PHP`).
- Additional useful service installed and configured (FTP server).

## What Was Done
### 1) VM Setup
1. Create a Debian stable VM in VirtualBox (or UTM).
2. Perform a minimal installation (no desktop environment).
3. Configure encrypted LVM partitions during installation.

### 2) Mandatory Security Configuration
1. Set hostname to `<login>42` (example: `adimas-d42`)
2. Install and configure OpenSSH on port `4242`
3. Disable root SSH login in `sshd_config`
4. Enable `ufw` and allow only required port(s)
5. Create user `<login>`, add to `sudo` and `user42`
6. Apply password aging + complexity policy
7. Configure strict `sudo` behavior and logging

### 3) Monitoring
`monitoring.sh` prints these metrics through `wall` at startup and every 10 minutes:
- architecture and kernel,
- physical/virtual CPU count,
- RAM and disk usage,
- CPU load,
- last reboot,
- LVM status,
- TCP connections,
- logged-in users,
- IP and MAC address,
- number of `sudo` commands.

### 4) Bonus Services
1. Deploy WordPress with `lighttpd` + `MariaDB` + `PHP`
2. Configure and justify one extra useful service
3. Additional useful service installed and configured (FTP server)

## Resources
- Debian Documentation: https://www.debian.org/doc/,
- AppArmor Documentation: https://wiki.debian.org/AppArmor,
- OpenSSH Documentation: https://man.openbsd.org/sshd,
- UFW Guide: https://help.ubuntu.com/community/UFW,
- LVM Documentation: https://wiki.debian.org/LVM,
- WordPress Documentation: https://wordpress.org/documentation/,
- lighttpd Documentation: https://redmine.lighttpd.net/projects/lighttpd/wiki,
- MariaDB Documentation: https://mariadb.com/kb/en/documentation/,
- PHP Documentation: https://www.php.net/docs.php,
- `cron` and `wall` manuals: `man 5 crontab`, `man wall`.

All server installation, configuration, testing, and project validation were completed manually.