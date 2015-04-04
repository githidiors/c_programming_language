#include <stdio.h>
#include <ctype.h>

#define IN		1 // inside a word
#define OUT		0 // outside a word
#define MAX_LEN  20 //maximum length of an English word

/*
	print a histogram of the length of words in a text file with the 
	horizontal bar
*/
void draw_histogram_horizontal(long words_cnt[], int len)
{
	int i = 0;
	int j;
	double cnt_sum = 0;
	long words_freq[MAX_LEN]; /*frequencies of word-length after normalization*/

	for (i = 1; i <= len; i++)
	{
		cnt_sum += words_cnt[i];
	}
	
	if (cnt_sum == 0)
		return;

	/*calculate the frequencies*/
	for (i = 1; i <= len; i++)
	{
		words_freq[i] = (long)(words_cnt[i] / cnt_sum * 200.0);
	}
	
	for (i = 1; i <= len; i++)
	{
		printf("%d: ", i);
		for (j = 1; j <= words_freq[i]; j++)
			printf("*");
		printf("\n");
	}
	
}

void draw_histogram_vertical(long words_cnt[], int len)
{
	int i = 0;
	int j;
	int max_freq = 0;
	double cnt_sum = 0;
	long words_freq[MAX_LEN]; /*frequencies of word-length after normalization*/
	
	for (i = 1; i <= len; i++)
	{
		cnt_sum += words_cnt[i];
	}

	/*calculate the frequencies*/
	for (i = 1; i <= len; i++)
	{
		words_freq[i] = (long)(words_cnt[i] / cnt_sum * 200.0);
	}

	for (i = 1; i <= len; ++i)
	{
		if (words_freq[i] > max_freq)
		{
			max_freq = words_freq[i];
		}
	}

	for (i = 1; i <= max_freq; i++)
	{
		for (j = 0; j < MAX_LEN; j++) {
			if (i < max_freq - words_freq[j+1])
				printf(" ");
			else
				printf("*");
			printf("  ");
		}
		printf("\n");
	}
	
	for (j = 0; j < MAX_LEN; j++) {
		printf("---");
	}
	printf("\n");

	for (j = 1; j <= MAX_LEN; j++) {
		printf("%-3d", j);
	}
	printf("\n");
}

void histogram_hor_len()
{
	FILE *fp;
	int c, i, len;
	int state = OUT;
	long words_cnt[MAX_LEN+1]; /*index 0 not used*/

	for (i = 0; i <= MAX_LEN; i++)
		words_cnt[i] = 0;
	len = 0;
	
	fp = fopen("test.txt", "r");
	if (NULL == fp)
	{
		printf("can't open the file, please check");
		return;
	}
	
	while ((c = getc(fp)) != EOF) {
		if (!isalpha(c))
		{
			if (state == IN)
			{
				words_cnt[len]++;
			}

			state = OUT;
			len = 0;
		}
		else
		{
			if (state == OUT)
			{
				len = 1;
			}
			else
			{
				len++;
			}
			state = IN;
		}
	}
	
	for (i = 1; i <= MAX_LEN; i++)
	{
		printf("%d %ld\n", i, words_cnt[i]);
	}

	/*print the frequencies of the word-length histogram*/
	draw_histogram_horizontal(words_cnt, MAX_LEN);
}

/*
	print a histogram of the length of words in a text file with the 
	vertical bar
*/
void histogram_ver_len()
{
	FILE *fp;
	int c, i, len;
	int state = OUT;
	long words_cnt[MAX_LEN+1]; /*index 0 not used*/
	
	for (i = 0; i <= MAX_LEN; i++)
		words_cnt[i] = 0;
	len = 0;
	
	fp = fopen("test.txt", "r");
	if (NULL == fp)
	{
		printf("can't open the file, please check");
		return;
	}
	
	while ((c = getc(fp)) != EOF) {
		if (!isalpha(c))
		{
			if (state == IN)
			{
				words_cnt[len]++;
			}
			
			state = OUT;
			len = 0;
		}
		else
		{
			if (state == OUT)
			{
				len = 1;
			}
			else
			{
				len++;
			}
			state = IN;
		}
	}
	
	for (i = 1; i <= MAX_LEN; i++)
	{
		printf("%d %ld\n", i, words_cnt[i]);
	}
	
	/*print the frequencies of the word-length histogram*/
	draw_histogram_vertical(words_cnt, MAX_LEN);
}

int main(int argc, char *argv[])
{
	histogram_ver_len();
	return 0;
}
