#ifndef _UTILS_H_
#define _UTILS_H_



void read_properties(char *pathname, char names[100][100], char values[100][100]);
void parseline(char *line, char *name, char *value);
char *rtrim(char *str);
char *trim(char *str);
char *ltrim(char *str);

void read_properties(char *pathname, char names[100][100], char values[100][100]){
	
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

void parseline(char *line, char *name, char *value){
	
    int length = 0, equal = 1; //equal will record the location of the '='
    char *begin;
	
    length = strlen(line);
	
    for(begin = line; *begin != '=' && equal <= length; begin ++){
		equal++;
    }
	
    strncpy(name, line, equal - 1); 
    line+=equal;
    strncpy(value, line, length - equal);
	
    printf("name=%s, value=%s.\n", trim(name), trim(value) ); //just for test, delete it later.
	
}

//去除尾部空格
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

//去除首部空格
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

//去除首尾空格
char *trim(char *str)
{
	str = rtrim(str);
	str = ltrim(str);
	
	return str;
	
}

#endif