Assignment No.7

A simple adblocking mechanism using iptables.

Christos Trimas
2016030054

After I resolve the domain names of the txt file using $dig, I save the ip addr in IPAddresses.txt file. Then the file is used as source in the following command:
	
		$sudo iptables -A(append) <name_of_chain> -s(source) <ip_addr_from_txt> -j REJECT

That way we tell that if a packet comes from this ip reject it.

In order to check our program, we can visit one of the domains or ips. A connection will not be established. But ads keep on appear from site to site. There are different explanations for that. One is that the packet could be ipv6, therefore we can not block it with iptables(I need ip6tables for that), or the site might not be on the list to block. Finally, some companies like google, they are clever than a simple firewall, therefore they might have found ways to skip those kind of simple adblockers.

To run the bash script choose one of the following:

	$sudo bash adblock.sh -<list_of_operations>

The tool supports the following operations:

	-domains:	Configure adblock rules based on the domain names of 'domainNames.txt' file
	-ips:		Configure adblock rules based on the IP addresses of 'IPAddresses.txt' file.
	-save:		Save rules to 'adblockRules' file.
	-load:		Loads rules to 'adblockRules' file.
	-list:		List current rules.
	-reset:		Reset rules to default settings (i.e. accept all).
	-help:		Help message.