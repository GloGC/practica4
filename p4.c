#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int my_head(){
	char arxiu;
	printf("Introdueix un arxiu: ");
	scanf("%d", &arxiu);
	char linies;
	printf("Introdueix número de línies: ");
	scanf("%d", &linies);

	fd = int open(const char * &arxiu, int O_RDONLY);
	
	if(fd == -1){
		printf("Error: l'arxiu no existeix, sortint del programa.);
		exit();
		}
	if(fd >= 0){
		if(wc -l == 0){
			printf("Error: l'arxiu està buit, sortint del programa.);
                	exit();
                }
		else{
			
