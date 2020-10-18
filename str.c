#include <stdio.h>
#include <assert.h>

#include "string.h"


// Return the length of the string pointed to by "s".
//
// Note: C standard library function strlen accomplishes
// exactly the same functionality as string_len. In this exercise,
// please do not use strlen. In subsequent exercises (list.c, htable.c), 
// it is recommended that you use strlen instead of string_len
int string_len(char *s)
{
  int i =0;
  while (s[i] != '\0')
{
	i++;
}
return i;
}

// Compare strings "s1" and "s2". It returns less than, equal to or great than zero 
// if "s1" is found to be less than, match, or larger than "s2" alphabetically.
// For example, string_cmp("aa", "aaa") should return a negative number
// and string_cmp("aa", "a0") should return a positive number
// Note that we use the ASCII values of characters as basis for comparison.
// As the ascii value of 'a' is greater than the ascii value of '0', 
// "aa" is considered to be greater than "a0".
//
// Note: C standard library function strcmp accomplishes
// exactly the same functionality as string_cmp. In this exercise,
// please do not use strcmp. In subsequent exercises (list.c, htable.c), 
// it is recommended that you use strcmp instead of string_cmp.
int string_cmp(char *s1, char *s2)
{
  int i = 0;
  int result1 = 0;
  while (s1[i] != '\0')
{
	result1 = result1 + (*s1) - '\n';
	i++;
}
  int j =0;
  int result2 = 0;
  while (s2[j] != '\0')
{
	result2 = result2 + (*s2) - '\n';
	j++;
}
  if(s1[0]>s2[0]){
  	return 1;
  }
  if(s1[0]<s2[0]){
  	return -1;
  }
  
  if (result1 < result2){
  	return -1;
  }
  if (result1 == result2){
  	return 0;
  }
  if (result1 > result2){
  	return 1;
  }
}

// Convert integer x into hex format and store the resulting hex string to "str",
// e.g., if x=16, then str should be "00000010".
// If x=26, then str should be "0000001a";
// The resulting hex string should always have exactly 8 hex characters 
// followed by the null character.
// We assume the caller has allocated an array of at least 9 characters for "str", 
// Note: please do not use formatted output, such as sprintf
void int_to_hex(unsigned int x, char *str)
{
  int i = 0;
  int first[4] = {2147483648,1073741824,536870912,268435456};
  int second[4] = {134217728,67108864,33554432,16777216};
  int third[4] = {8388608,4194304,2097152,1048576};
  int fourth[4] = {524288,262144,131072,65536};
  int fifth[4] = {32768,16384,8192,4096};
  int sixth[4] = {2048,1024,512,256};
  int seventh[4] = {128,64,32,16};
  int eigth[4] = {8,4,2,1};

  for(i=0;i<4;i++){
  	if((x%first[i])!=x){
      x = x%first[i];
  		first[i] = 1;
  	} 
  	else{
  		first[i] = 0;		
  	}
  }
  for(i=0;i<4;i++){
  	if((x%second[i])!=x){
      x = x%second[i];
  		second[i] = 1;
  	} 
  	else{
  		second[i] = 0;		
  	}
  }
  for(i=0;i<4;i++){
  	if((x%third[i])!=x){
      x = x%third[i];
  		third[i] = 1;
  	} 
  	else{
  		third[i] = 0;		
  	}
  }
  for(i=0;i<4;i++){
  	if((x%fourth[i])!=x){
      x = x%fourth[i];
  		fourth[i] = 1;
  	} 
  	else{
  		fourth[i] = 0;		
  	}
  }
  for(i=0;i<4;i++){
  	if((x%fifth[i])!=x){
      x = x%fifth[i];
  		fifth[i] = 1;
  	} 
  	else{
  		fifth[i] = 0;		
  	}
  }
  for(i=0;i<4;i++){
  	if((x%sixth[i])!=x){
      x = x%sixth[i];
  		sixth[i] = 1;
  	} 
  	else{
  		sixth[i] = 0;		
  	}
  }
  for(i=0;i<4;i++){
  	if((x%seventh[i])!=x){
      x = x%seventh[i];
  		seventh[i] = 1;
  	} 
  	else{
  		seventh[i] = 0;		
  	}
  }
  
  for(i=0;i<4;i++){
  	if((x%eigth[i])!=x){
      x = x%eigth[i];
  		eigth[i] = 1;
  	} 
  	else{
  		eigth[i] = 0;		
  	}
  }	
  

  int res1 = first[0]*8 + first[1]*4 + first[2]*2 + first[3];
  int res2 = second[0]*8 + second[1]*4 + second[2]*2 + second[3];
  int res3 = third[0]*8 + third[1]*4 + third[2]*2 + third[3];
  int res4 = fourth[0]*8 + fourth[1]*4 + fourth[2]*2 + fourth[3];
  int res5 = fifth[0]*8 + fifth[1]*4 + fifth[2]*2 + fifth[3];
  int res6 = sixth[0]*8 + sixth[1]*4 + sixth[2]*2 + sixth[3];
  int res7 = seventh[0]*8 + seventh[1]*4 + seventh[2]*2 + seventh[3];
  int res8 = eigth[0]*8 + eigth[1]*4 + eigth[2]*2 + eigth[3];

  int res[8] = {res1,res2,res3,res4,res5,res6,res7,res8};
  char resChar[8] = {'a','a','a','a','a','a','a','a'};
  int index = 0;
  
  for(i=0; i<8; i++){
    if (res[i]==0){
      resChar[i] = '0';
    }
    if (res[i]==1){
      resChar[i] = '1';
    }
    if (res[i]==2){
      resChar[i] = '2';
    }
    if (res[i]==3){
      resChar[i] = '3';
    }
    if (res[i]==4){
      resChar[i] = '4';
    }
    if (res[i]==5){
      resChar[i] = '5';
    }
    if (res[i]==6){
      resChar[i] = '6';
    }
    if (res[i]==7){
      resChar[i] = '7';
    }
    if (res[i]==8){
      resChar[i] = '8';
    }
    if (res[i]==9){
      resChar[i] = '9';
    }
  	if (res[i]==10){
  		resChar[i] = 'a';
  	}
  	if (res[i]==11){
  		resChar[i] = 'b';
  	}
  	if (res[i]==12){
  		resChar[i] = 'c';
  	}
  	if (res[i]==13){
  		resChar[i] = 'd';
  	}
  	if (res[i]==14){
  		resChar[i] = 'e';
  	}
  	if (res[i]==15){
  		resChar[i] = 'f';
  	}
  }
  for(i=0;i<8;i++){
    str[i] = resChar[i];
  }
  }




