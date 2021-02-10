#include<stdio.h>


double convToFarenheit ( double temp )
{
  return (9.0/5.0) * temp + 32.0;
}

int isValidInput (float currTemp, char tempSign, char addOrMin)
{
  
  if (tempSign != 'f' || tempSign != 'c')
     //input has plus or minus with no value on both sides
  {
    return 2;
  }
  else if (addOrMin != '+' || addOrMin != '-')
  {
    return 2;

  }  
  else if()
  {
    //if input includes a letter other than c or f
    return 2;
  }
  else
  {
    return 0;
  }
}

int main ()
{
  printf("Please enter the weather trend using + and - only:");
  float currTemp;
  int numInput = 0;
  char tempSign;
  char addOrMin;
  int isValidTester = 0;
  float finalTemp = 0;

  int initScan = scanf(" %f %c", &currTemp, &tempSign);
  if (initScan != 2) {
    printf("malformed expression\n");
    
  }
  while(  (numInput = scanf("%c %f %c", &currTemp, &tempSign, &addOrMin) != EOF) {
     

  }
  scanf("%f %c %c", &currTemp, &tempSign, &addOrMin);
  isValidTester = isValidInput(currTemp, tempSign, addOrMin);
  if (isValidTester == 1)
    {
      printf("malformed expression\n");
      assert(isValidTester == 0);
    }
  
  if (isValidTester == 2)
    {
      printf("invalid unit \n");
      assert(isValidTester == 0);
    }
    finalTemp += currTemp;
    //assume code runs correctly
  float finalAns = 


}
