#ifndef _UTILS_H_
#define _UTILS_H_
#include <map>
#include <string>
using namespace std;  

static map<string, string> mGlobal;

void read_properties(char *pathname, char names[100][100], char values[100][100]);
void parseline(char *line, char *name, char *value);
char *rtrim(char *str);
char *trim(char *str);
char *ltrim(char *str);
void read_properties(char *pathname);
void parseline(char *line);

void read_properties(char *pathname)
{	
    FILE *file;
    char line[100];
    int i = 0;
	
    file = fopen(pathname, "r");
    while(fgets(line, 100, file)){
        printf("%s\n", line);                             //just for test, delete it later.
        parseline(line);
        i++;
    }
	
    fclose(file); 
}

void parseline(char *line)
{
    int length = 0, equal = 1; //equal will record the location of the '='
    char *begin;
	
    length = strlen(line);
	
    for(begin = line; *begin != '=' && equal <= length; begin ++){
		equal++;
    }

	char name[100];
	char value[100];
	
    strncpy(name, line, equal - 1); 
	name[equal-1] = '\0';//�ַ���������

    line+=equal;//ָ�������ƶ�

    strncpy(value, line, length - equal);
	value[length - equal] = '\0';//�ַ���������

	mGlobal.insert(pair<string,string>(trim(name),trim(value)) ); 
}

void read_properties(char *pathname, char names[100][100], char values[100][100])
{	
    FILE *file;
    char line[100];
    int i = 0;
	
    file = fopen(pathname, "r");
    while(fgets(line, 100, file)){
        printf("%s\n", line);                             //just for test, delete it later.
        parseline(line, names[i], values[i]);
        i++;
    }
	
	
    fclose(file); 
}

void parseline(char *line, char *name, char *value)
{
    int length = 0, equal = 1; //equal will record the location of the '='
    char *begin;
	
    length = strlen(line);
	
    for(begin = line; *begin != '=' && equal <= length; begin ++){
		equal++;
    }
	
    strncpy(name, line, equal - 1); 
    line+=equal;//ָ�������ƶ�
    strncpy(value, line, length - equal);
	name = trim(name);
	value = trim(value);
	
    printf("name=%s, value=%s.\n", name, value ); //just for test, delete it later.
	
}

//ȥ��β���ո�
char *rtrim(char *str)
{
	if (str == NULL || *str == '\0')
	{
		return str;
	}
	
	int len = strlen(str);
	char *p = str + len - 1;
	while (p >= str  && isspace(*p))
	{
		*p = '\0';
		--p;
	}
	
	return str;
}

//ȥ���ײ��ո�
char *ltrim(char *str)
{
	if (str == NULL || *str == '\0')
	{
		return str;
	}
	
	int len = 0;
	char *p = str;
	while (*p != '\0' && isspace(*p))
	{
		++p;
		++len;
	}
	
	memmove(str, p, strlen(str) - len + 1);
	
	return str;
}

//ȥ����β�ո�
char *trim(char *str)
{
	str = rtrim(str);
	str = ltrim(str);
	
	return str;
	
}

#endif