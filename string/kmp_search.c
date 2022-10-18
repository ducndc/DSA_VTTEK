/**
 * KMP Algorithm for Pattern Searching
 * 
 * O(n)
 * */

#include <stdio.h>

#define IN(str) (scanf("%s", str))

void compute_LPS_array(char* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
    lps[0] = 0; // lps[0] is always 0
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) 
	{
        if (pat[i] == pat[len]) 
		{
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) 
			{
                len = lps[len - 1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMP_search(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int count = 0;
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
    // Preprocess the pattern (calculate lps[] array)
    compute_LPS_array(pat, M, lps);
    
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((N - i) >= (M - j)) 
	{
        if (pat[j] == txt[i]) 
		{
            j++;
            i++;
        }
        if (j == M) 
		{
            //printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
            count += 1;
        }
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) 
		{
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }

    return count;
}

int main(){
	char P[100000];
	char T[100000];
	IN(P);
	IN(T);
	printf("%d", KMP_search(P, T));
    return 0;
}
    for(int i = 0 ; i * i <= 2*(N + 1) ; i++){
            int j = (N + 1 + i)/(i + 1) - 1;
            ans = min(ans, i + j);
        }