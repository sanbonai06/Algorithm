#include<stdio.h>
long long count[1000];
long long result = 0;

int main() {
	FILE* fp;
	fp = fopen("anna-karerina.txt", "r");

	char w = 'a';
	while(w != EOF) {
		w = getc(fp);
		// printf("%c\n", w);
		if(w>= 0 && w<= 127)
			count[w]++;
		else continue;
	}
	fclose(fp);
	for(int i=0; i<=127; i++) {
		if(count[i] > 200000) result++;
		printf("count[%d] : %lld\n", i, count[i]);
	}
	printf("%lld",result);
}


