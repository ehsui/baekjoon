#include <stdio.h>

int main(void)
{
	char temp, temp1;
	int i = 0, num;
	temp = getchar();
	if (temp != ' ' && temp != '\n') num = 1;
	else if (temp == '\n') {
		printf("0");
		return 0;
	}
	else {
		num = 0;
		i = 1;
	}

	while ((temp = getchar()) != '\n')
	{

		if (temp == ' ') {
			i = 1;
		}
		else {
			if (i == 1) {
				num += 1;
				i = 0;
			}
		}
	}


	printf("%d", num);
	return 0;
}
