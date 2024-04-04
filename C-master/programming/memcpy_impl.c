#include<stdio.h>
#include<string.h>

/*void *my_strcpy(char *dest, char *src, int n)
{
	int i = 0;
	
	if(src != NULL && dest != NULL)
	{
		while(i < n)
			dest[i] = src[i++];
		dest[i] = '\0';
	}
	else
		dest = NULL;
	//printf("%s: %s\n", __func__, dest);
	return (void *)dest;
}*/

void *my_memcpy(void *dest, void *src, int n)
{
        int i = 0;
	const char *tmp_src = (const char *)src;
	char *tmp_dest = (char *)dest;
        if(src != NULL && dest != NULL)
        {
                while(i < n)
		{
			printf("Byte: %d\n", i);
                        tmp_dest[i] = tmp_src[i++];
		}
                //tmp_dest[i] = '\0';
        }
        else    
                dest = NULL;
        //printf("%s: %s\n", __func__, dest);
        return dest;
}

void * Memcpy_web(void* dst, const void* src, unsigned int cnt)
{
    char *pszDest = (char *)dst;
    const char *pszSource =( const char*)src;
    if((pszDest!= NULL) && (pszSource!= NULL))
    {
        while(cnt) //till cnt
        {
            //Copy byte by byte
            *(pszDest++)= *(pszSource++);
            --cnt;
        }
    }
    return dst;
}

int main()
{
	char buf1[20], buf2[20];
	int arr[] = {1, 2, 3, 4, 5};
	int arr1[5], i = 0;

//	printf("entered string to get copied:\n");
//	scanf("%s", buf1);
//	memcpy(buf2, buf1, strlen(buf1));
//	printf("library func: %s\n", buf2);
//	memset(buf2, '\0', sizeof(buf2));
//	printf("after get empty: %s\n calling my func for copy\n", buf2);
//	my_strcpy();
	memcpy(arr1, arr, (sizeof(arr) * 4));
	printf("library func:\n");
	for(i = 0; i < 5; i++)
		printf("%d ", arr1[i]);
	printf("\n");
	memset(arr1, 0, (sizeof(arr1) * 4));
	printf("after getting empty\n");
	for(i = 0; i < 5; i++)
                printf("%d ", arr1[i]);	
	printf("\n");
	printf("after calling my func:\n");
	Memcpy_web((void *)arr1, (void *)arr, (sizeof(arr1) * 4));
//	my_memcpy((void *)arr1, (void *)arr, (sizeof(arr1) * 4));
	for(i = 0; i < 5; i++)
                printf("%d ", arr1[i]);	
	printf("\n");
	printf("after printing:\n");
	return 0;
}
