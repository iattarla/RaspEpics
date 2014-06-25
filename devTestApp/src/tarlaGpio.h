/*******************************************************
*	gpio library 
*
*	library is not need sudo 
*
*	developer: Bilal Tonga
*
*
*
*
*******************************************************/
/*
*	digitalWrite();
*/ 

void digitalWrite(int portNumber,int portStatus){

  char command[50];

  char portString[2];
  
  char statusString[2];

  sprintf(portString, "%d", portNumber);
  sprintf(statusString, "%d", portStatus);
  
  strcpy( command, "gpio write " );
  strcat( command, portString );
  strcat( command, " " );
  strcat( command, statusString );
  system(command);

}
/*
* 	pinMode();
*/
void pinMode(int portNumber,char portType[6]){

  char command[50];

  char portString[2];
  
  //char typeString[2];

  sprintf(portString, "%d", portNumber);
  //sprintf(typeString, "%d", portType);
  
  strcpy( command, "gpio mode " );
  strcat( command, portString );
  strcat( command, " " );
  strcat( command, portType );
  system(command);

}
/*
*        digitalRead();
*/
int digitalRead(int portNumber){

  char command[50];

  char portString[2];
  
  FILE *fp;
  int portStatus = 0;
  char path[10];
 

  sprintf(portString, "%d", portNumber);

  
  strcpy( command, "gpio read " );
  strcat( command, portString );
  //int portStatus = system(command);
  
  /* Open the command for reading. */
  fp = popen(command, "r");
  
	if (fp == NULL) {
	    printf("Failed to run command\n" );
	    exit;
  	}

    /* Read the output a line at a time - output it. */
    while (fgets(path, sizeof(path)-1, fp) != NULL) {

    printf("string :%c:", path[0]);
  }

  /* close */
  pclose(fp);

  //sprintf(path[0], "%d", portStatus);
  portStatus = path[0]  - '0';

  printf("port status : %d\n",portStatus);
  
return portStatus;



}
