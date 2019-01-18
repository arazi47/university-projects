### Generated data

```
Network IP: 121.6.245.192
Mask: 255.255.255.192 (/26)
Sub networks:
N1: 12 IPs
N2: 12 IPs
N3: 4 IPs
N4: 5 IPs
N5: 1 IPs
```

I had to setup static routing, NAT on R2, DHCP on one of the routers, a website (google.com) that every PC can access.

NOTE: There is one problem with the project. I cannot set the DNS server for the PCs in the subnetwork with the DHCP server, so they cannot access the website.