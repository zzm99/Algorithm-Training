#include <iostream>
#include <cstdio>
#include <string.h>
#include <map>
using namespace std;

const int maxn = 100005;
int num = 0;

char mz[maxn][50];
char zy[maxn][100];

map<int, int> mpmz, mpzy;

unsigned int myhash(char* s)
{
    unsigned int seed = 131;
    unsigned int h = 0;
    while (*s) h = h * seed + (*s++);
    return (h & 0x7FFFFFFF);
}

void init() {
	for(int i=1; i<num; i++) {
		mpmz[myhash(mz[i])] = i;
		mpzy[myhash(zy[i])] = i;
	}
}

int main() {
	freopen("test.txt", "r", stdin);

	num = 1;
	while(1) {
		scanf("%s",mz[num]);
		if(mz[num][0] == '@') break;
		getchar();
		fgets(zy[num], 100, stdin);
		zy[num][strlen(zy[num])-1] = '\0';
		num++;
	}
	init();
	int n = 0;
	cin >> n;
	getchar();
	while(n--) {
        char t[100];
        fgets(t, 100, stdin);
		t[strlen(t)-1] = '\0';
		if(t[0] == '[') {
			int tmp = mpmz[myhash(t)];
            if (tmp == 0) printf("%s\n","what?");
            else printf("%s\n",zy[tmp]);
		} else {
			int tmp = mpzy[myhash(t)];
			if (tmp == 0) printf("%s\n","what?");
            else
            {
                for (int j = 1;j < strlen(mz[tmp]) - 1;j++)
                    printf("%c",mz[tmp][j]);
                printf("\n");
            }
		}
	}
	return 0;
}
