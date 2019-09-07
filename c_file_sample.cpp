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
    

	fseek( stream, 0L, SEEK_END );       /* ��λ���ļ�ĩβ */
	lflen = ftell( stream );         /* �õ��ļ���С */
	p = (char *) malloc( lflen + 1 ); /* �����ļ���С��̬�����ڴ�ռ� */
	fseek( stream, 0L, SEEK_SET );       /* ��λ���ļ���ͷ */
	fread( p, lflen, 1, stream );        /* һ���Զ�ȡȫ���ļ����� */
	p[lflen] = '\0';             /* �ַ���������־ */
	printf( "%s\n", p );
	fclose( stream );
	free( p );

	//char data[100];
    //��һ���ļ����ж�����,��ȡ5��Ԫ��,ÿ��Ԫ��1�ֽ�.    
	/*
    while(fread(data, 1,sizeof(data), stream) != 0) {
        printf("%s",data);
    }
	*/
    //һ�δ��ļ��ж�ȡ4���ֽ����ݵ�data������    
    /*
	while (fgets(data, 100, stream)!=NULL) {
        printf("%s",data);
    }
	*/

	char names[100][100], values[100][100];
	
	read_properties("propertis.cfg", names, values);
    return 0;
}


