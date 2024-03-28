#include <stdio.h>
#include <string.h>

int main(void)
{
	int check = 0, len_ch, ary[26] = { 0, };
	char ch[1000001];
	int max = ary[0];
	int ans = 0;

	scanf("%s", ch);

	len_ch = strlen(ch);
	
	for (int i = 0; i < len_ch; i++) {
		if (ch[i] >= 'a' && ch[i] <= 'z') {
			ary[ch[i] - 'a'] += 1;
		}
		else {
			ary[ch[i] - 'A'] += 1;
		}
	}

	for (int k = 0; k < 26; k++) {
		if (ary[k] >= max) {
			max = ary[k];
			ans = k;
		}
	} // 가장 많은 알파벳 고르기

	for (int k = 0; k < 26; k++) {
		if (max == ary[k]){
			check++;
		}
	} // ?출력 확인

	max = ans + 'A';

	if (check > 1) printf("?");
	else printf("%c", (char)max);

	return 0;
}
