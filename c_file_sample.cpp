// c_file_sample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

int main(int argc, char* argv[])
{
	FILE *stream;
    long lflen;
	char *p;
    if ((stream = fopen("propertis.cfg", "r")) == NULL) {
        fprintf(stderr,"Cannot open output file.\n");        
        return 1;    
    }
    

	fseek( stream, 0L, SEEK_END );       /* 定位到文件末尾 */
	lflen = ftell( stream );         /* 得到文件大小 */
	p = (char *) malloc( lflen + 1 ); /* 根据文件大小动态分配内存空间 */
	fseek( stream, 0L, SEEK_SET );       /* 定位到文件开头 */
	fread( p, lflen, 1, stream );        /* 一次性读取全部文件内容 */
	p[lflen] = '\0';             /* 字符串结束标志 */
	printf( "%s\n", p );
	fclose( stream );
	free( p );

	//char data[100];
    //从一个文件流中读数据,读取5个元素,每个元素1字节.    
	/*
    while(fread(data, 1,sizeof(data), stream) != 0) {
        printf("%s",data);
    }
	*/
    //一次从文件中读取4个字节数据到data数组中    
    /*
	while (fgets(data, 100, stream)!=NULL) {
        printf("%s",data);
    }
	*/

	char names[100][100], values[100][100];
	
	read_properties("propertis.cfg", names, values);
    return 0;
}


