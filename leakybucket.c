#include<stdio.h>

int main()
{
	int nop,bs,A[10],SP[10],bal,or,z=0;
	
	// Reading of input
	
	printf("Enter the Bucket Size: ");
	scanf("%d",&bs);
	printf("Enter the Output Rate: ");
	scanf("%d",&or);
	printf("Enter the Number of Packets: ");
	scanf("%d",&nop);
	int i,j,temp;
	for(i=0;i<nop;i++)
	{
		printf("Enter Arrival Time: ");
		scanf("%d",&A[i]);
		printf("Enter the Size of Packet: ");
		scanf("%d",&SP[i]);
	}
		bal=0;
		for(i=0;i<nop;i++)
		{
		if(bs>=(SP[i]+bal)&&(SP[i]+bal)>=or)
		{
			bal=bal+SP[i]-or;		
			printf("AT TIME %d:\n %d Bytes of Packet is inserted.\n %d Bytes of Packet is Transferred.\n %d Bytes of Packet is remaining in the Bucket.\n\n",A[i],SP[i],or,bal);
			
		}
		else if(bs>=(SP[i]+bal)&&(SP[i]+bal)<or)
		{
			printf("AT TIME %d:\n %d Bytes of Packet is inserted.\n %d Bytes of Packet is Transferred.\n %d Bytes of Packet is remaining in the Bucket.\n\n",A[i],SP[i],SP[i],bal);
			bal=z;
		}
		
		else if(SP[i]>bs)
                {
           		printf("Bucket Overflow \n");
                }
                
		else
		{
			if(bal>=or)
			{
				bal=bal-or;
				printf("AT TIME %d:\n %d Bytes of Packet is inserted.\n %d Bytes of Packet is Transferred.\n %d Bytes of Packet is remaining in the Bucket.\n\n",A[i],SP[i],or,bal);
			
			}
			else
			{
				printf("AT TIME %d:\n %d Bytes of Packet is inserted.\n %d Bytes of Packet is Transferred.\n %d Bytes of Packet is remaining in the Bucket.\n\n",A[i],SP[i],or,bal);
				bal=z;
			
			}
		}
	}
	
	while(bal>0)
	{
		if(bal>=or)
		{
			bal=bal-or;
			printf("%d Bytes of Packet is Transferred.\n%d Bytes of Packet is Remaining in the Bucket.\n\n",or,bal);
		}
		else if(bal==0)
		{
			printf("NO Bytes of Packet is remaining\n");
		}
		else
		{
			printf("%d Bytes of Packet is Transferred.\n",bal);
			bal=z;
			printf("%d Bytes is Remaining.\n",z);
		}
	}
}					
								
					
