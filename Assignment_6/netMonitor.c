#include "netMonitor.h"

void usage(void)
{
	printf(
	       "\n"
	       "usage:\n"
	       "\t./monitor \n"
		   "Options:\n"
		   "-i Network interface name (e.g., eth0)\n"
		   "-r,Packet capture file name (e.g., test.pcap)\n"
		   "-h, Help message\n\n"
		   );

	exit(1);
}

int main(int argc, char *argv[])
{

	int ch;
	char *dev = NULL;			 capture device name 
	u_char *filename=NULL;

	if (argc < 2)
	    usage();

	while ((ch = getopt(argc, argv, "h:i:r:")) != -1) {

		switch (ch) {		
		case 'i':
			// dev=optarg;
			// liveMode(dev);
			break;
		case 'r':
			// filename=optarg;
			// offlineMode(filename);
			break;
		default:
			usage();
		}
	}
	argc -= optind;
	argv += optind;	
	return 0;
}
