#include <stdio.h>
#include <malloc.h>
typedef struct linked_list{
	int add;
	int data;	
}anode,*panode;

int main(){
	int head,num,length,temp,block,rest,i,j;
	int tag=0;
	
	scanf("%d %d %d",&head,&num,&length);
	
	 int* data = (int *)malloc(sizeof(int)*1000004);
     int* next = (int *)malloc(sizeof(int)*1000004);
	panode ans = (panode)malloc(sizeof(anode)*(num+1));
	
	for(i=0;i<num;i++){
		scanf("%d",&temp);
		scanf("%d %d",&data[temp],&next[temp]);
	}
	while(head!=-1){
		ans[tag].data=data[head];
		ans[tag].add=head;
		head=next[head];
		tag++;
	}
//	printf("%d\n",tag);3
	block=tag/length;
	rest=tag%length;
	for(i=0;i<block;i++){
		for(j=(i+1)*length-1;j>i*length;j--){
			printf("%05d %d %05d\n",ans[j].add,ans[j].data,ans[j-1].add);
		}	
		printf("%05d %d ",ans[j].add,ans[j].data);
			if(rest==0){
				if(i==block-1){
					printf("-1");
				}
				else{
					printf("%05d\n",ans[(i+2)*length-1].add);
				}
			} else {
				if(i==block-1){
					printf("%05d\n",ans[tag-rest].add);
				}
				else{
					printf("%05d\n",ans[(i+2)*length-1].add);
				}
			}
	}
	if(rest!=0){
		for(i=tag-rest;i<tag-1;i++)
		printf("%05d %d %05d\n",ans[i].add,ans[i].data,ans[i+1].add);
		printf("%05d %d -1",ans[i].add,ans[i].data);
	}	
}
 
