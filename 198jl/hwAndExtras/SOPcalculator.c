#include <stdio.h>
#include <string.h>
int main(){
	int x = 0;
	/*Initial Equation Register and general help guide*/
	printf("\n");
	printf("	Welcome to the Function Calculator!\n");
	printf("	Enter the function you wish to compute...\n");
	printf("	[Commands: & - AND, ! - NOT, | - OR, ^ - XOR]\n");
	printf("	**NOTE: This Generator is limited to 4 inputs (a,b,c,d),\n 		DO NOT USE SPACES!!!**\n");
	printf("	**NOTE: This builder only supports up to four tier\n 		parenthesis expressions, i.e. a|(b&(c^(!d))))**\n");
	printf("	**NOTE: This builder will read the boolean expression from\n 		left to right, so separate with parenthesis for order.**\n");
	printf("\n");
	do{
		char functionInput[32];
		char functionOutput[32];
		unsigned int a, b, c, d, varSetup, functionFinal, function1, function2, function3, function4;
		int varAND = 0, varOR = 0, varNOT = 0, varXOR = 0;
		int varAND1 = 0, varOR1 = 0, varNOT1 = 0, varXOR1 = 0;
		int varAND2 = 0, varOR2 = 0, varNOT2 = 0, varXOR2 = 0;
		int varAND3 = 0, varOR3 = 0, varNOT3 = 0, varXOR3 = 0;
		int varAND4 = 0, varOR4 = 0, varNOT4 = 0, varXOR4 = 0;
		int startFunction = 0, checkVar = 0, functionOrder = 0, checkOperand = 0;
		int inputNumber = 0;
		int outCheck = 1;
		printf("How many inputs (3 or 4)?: ");
		scanf("%d", &inputNumber);
		printf("\n");
		printf("Enter Function: ");
		scanf("%s", functionInput);
		printf("\n");
		if (inputNumber == 3){
			printf("Truthtable:\n");
			printf("\n");
			printf("  A  B  C | OUT \n");
			printf("----------|-----\n");
			for (a = 0; a <= 1; a = a + 1){
				for (b = 0; b <= 1; b = b + 1){
					for (c = 0; c <= 1; c = c + 1){
						for (int i = 0; functionInput[i] != '\0'; i = i + 1){
							if (functionInput[i] == 'a'){
								checkVar = checkVar + 1;
								varSetup = a;
							}
							else if (functionInput[i] == 'b'){
								checkVar = checkVar + 1;
								varSetup = b;
							}
							else if (functionInput[i] == 'c'){
								checkVar = checkVar + 1;
								varSetup = c;
							}
							else if (functionInput[i] == '!'){
								varNOT = 1;
							}
							else if (functionInput[i] == '&'){
								varAND = 1;
								checkOperand = checkOperand + 1;
							}
							else if (functionInput[i] == '|'){
								varOR = 1;
								checkOperand = checkOperand + 1;
							}
							else if (functionInput[i] == '^'){
								varXOR = 1;
								checkOperand = checkOperand + 1;
							}
							else if (functionInput[i] == '('){
								functionOrder = functionOrder + 1;
								if (functionOrder == 1){
									varNOT1 = varNOT;
									varAND1 = varAND;
									varOR1 = varOR;
									varXOR1 = varXOR;
								}
								else if (functionOrder == 2){
									varNOT2 = varNOT;
									varAND2 = varAND;
									varOR2 = varOR;
									varXOR2 = varXOR;
								}
								else if (functionOrder == 3){
									varNOT3 = varNOT;
									varAND3 = varAND;
									varOR3 = varOR;
									varXOR3 = varXOR;
								}
								else if (functionOrder == 4){
									varNOT4 = varNOT;
									varAND4 = varAND;
									varOR4 = varOR;
									varXOR4 = varXOR;
								}
								else{
									printf("ERROR: CHECK PARENTHESIS, ENDING PROGRAM...\n");
									return 0;
								}
								checkOperand = 0;
								varNOT = 0;
								varAND = 0;
								varOR = 0;
								varXOR = 0;
							}
							else if (functionInput[i] == ')'){
								if (functionOrder == 1){
									if (startFunction == 1){
										if (varNOT1 == 1){
											function1 = !function1;
											varNOT1 = 0;
										}
										if (varAND1 == 1){
											function1 = functionFinal & function1;
											varAND1 = 0;
										}
										else if (varOR1 == 1){
											function1 = functionFinal | function1;
											varOR1 = 0;
										}
										else if (varXOR1 == 1){
											function1 = functionFinal ^ function1;
											varXOR1 = 0;
										}
										functionFinal = function1;
									}
									else{
										if (varNOT1 == 1){
											function1 = !function1;
											varNOT1 = 0;
										}
										startFunction = 1;
										functionFinal = function1;
									}
								}
								else if (functionOrder == 2){
									if (varNOT2 == 1){
										function2 = !function2;
										varNOT2 = 0;
									}
									if (varAND2 == 1){
										function2 = function1 & function2;
										varAND2 = 0;
									}
									else if (varOR2 == 1){
										function2 = function1 | function2;
										varOR2 = 0;
									}
									else if (varXOR2 == 1){
										function2 = function1 ^ function2;
										varXOR2 = 0;
									}
									function1 = function2;
								}
								else if (functionOrder == 3){
									if (varNOT3 == 1){
										function3 = !function3;
										varNOT3 = 0;
									}
									if (varAND3 == 1){
										function3 = function2 & function3;
										varAND3 = 0;
									}
									else if (varOR3 == 1){
										function3 = function2 | function3;
										varOR3 = 0;
									}
									else if (varXOR3 == 1){
										function3 = function2 ^ function3;
										varXOR3 = 0;
									}
									function2 = function3;
								}
								else if (functionOrder == 4){
									if (varNOT4 == 1){
										function4 = !function4;
										varNOT4 = 0;
									}
									if (varAND4 == 1){
										function4 = function3 & function4;
										varAND4 = 0;
									}
									else if (varOR4 == 1){
										function4 = function3 | function4;
										varOR4 = 0;
									}
									else if (varXOR4 == 1){
										function4 = function3 ^ function4;
										varXOR4 = 0;
									}
									function3 = function4;
								}
								else{
									printf("ERROR: CHECK PARENTHESIS, ENDING PROGRAM...\n");
									return 0;
								}
								functionOrder = functionOrder - 1;
							}
							else{
								printf("ERROR: NOT A VALID ENTRY, ENDING PROGRAM...\n");
								return 0;
							}
							if (checkVar > 1){
								printf("ERROR: CHECK VARIABLES, ENDING PROGRAM...\n");
								return 0;
							}
							if (checkOperand > 1){
								printf("ERROR: CHECK OPERANDS, ENDING PROGRAM...\n");
								return 0;
							}
							if (functionInput[i] == '(' && functionInput[i+1] == ')'){
								printf("ERROR: CHECK PARENTHESIS, ENDING PROGRAM...\n");
								return 0;
							}
							if (checkVar == 1){
								if (functionOrder == 0){
									if (varNOT == 1){
										varSetup = !varSetup;
										varNOT = 0;
									}
									if (varAND == 1){
										varSetup = functionFinal & varSetup;
										varAND = 0;
									}
									else if (varOR == 1){
										varSetup = functionFinal | varSetup;
										varOR = 0;
									}
									else if (varXOR == 1){
										varSetup = functionFinal ^ varSetup;
										varXOR = 0;
									}
									functionFinal = varSetup;
								}
								else if (functionOrder == 1){
									if (varNOT == 1){
										varSetup = !varSetup;
										varNOT = 0;
									}
									if (varAND == 1){
										varSetup = function1 & varSetup;
										varAND = 0;
									}
									else if (varOR == 1){
										varSetup = function1 | varSetup;
										varOR = 0;
									}
									else if (varXOR == 1){
										varSetup = function1 ^ varSetup;
										varXOR = 0;
									}
									function1 = varSetup;
								}
								else if (functionOrder == 2){
									if (varNOT == 1){
										varSetup = !varSetup;
										varNOT = 0;
									}
									if (varAND == 1){
										varSetup = function2 & varSetup;
										varAND = 0;
									}
									else if (varOR == 1){
										varSetup = function2 | varSetup;
										varOR = 0;
									}
									else if (varXOR == 1){
										varSetup = function2 ^ varSetup;
										varXOR = 0;
									}
									function2 = varSetup;
								}
								else if (functionOrder == 3){
									if (varNOT == 1){
										varSetup = !varSetup;
										varNOT = 0;
									}
									if (varAND == 1){
										varSetup = function3 & varSetup;
										varAND = 0;
									}
									else if (varOR == 1){
										varSetup = function3 | varSetup;
										varOR = 0;
									}
									else if (varXOR == 1){
										varSetup = function3 ^ varSetup;
										varXOR = 0;
									}
									function3 = varSetup;
								}
								else if (functionOrder == 4){
									if (varNOT == 1){
										varSetup = !varSetup;
										varNOT = 0;
									}
									if (varAND == 1){
										varSetup = function4 & varSetup;
										varAND = 0;
									}
									else if (varOR == 1){
										varSetup = function4 | varSetup;
										varOR = 0;
									}
									else if (varXOR == 1){
										varSetup = function4 ^ varSetup;
										varXOR = 0;
									}
									function4 = varSetup;
								}
								checkOperand = 0;
								checkVar = 0;
							}
						}
						printf("  %d  %d  %d |  %d  \n", a, b, c, functionFinal);
						if (functionFinal == 1){
							functionOutput[outCheck] = '1';
						}
						else{
							functionOutput[outCheck] = '0';
						}
						outCheck = outCheck + 1;
					}
				}
			}
			printf("----------|-----\n");
			printf("\n");
			printf("\n");
			printf("K-Map:\n");
			printf("                BC\n");
			printf("       0 0   0 1   1 1   1 0\n");
			printf("     |-----|-----|-----|-----|\n");
			printf("   0 |  %c  |  %c  |  %c  |  %c  |\n", functionOutput[1], functionOutput[2], functionOutput[4], functionOutput[3]);
			printf(" A   |-----|-----|-----|-----|\n");
			printf("   1 |  %c  |  %c  |  %c  |  %c  |\n", functionOutput[5], functionOutput[6], functionOutput[8], functionOutput[7]);
			printf("     |-----|-----|-----|-----|\n");
		}
		else if (inputNumber == 4){
			printf("Truthtable:\n");
			printf("\n");
			printf("  A  B  C  D | OUT \n");
			printf("-------------|-----\n");
			for (a = 0; a <= 1; a = a + 1){
				for (b = 0; b <= 1; b = b + 1){
					for (c = 0; c <= 1; c = c + 1){
						for (d = 0; d <= 1; d = d + 1){
							for (int i = 0; functionInput[i] != '\0'; i = i + 1){
								if (functionInput[i] == 'a'){
									checkVar = checkVar + 1;
									varSetup = a;
								}
								else if (functionInput[i] == 'b'){
									checkVar = checkVar + 1;
									varSetup = b;
								}
								else if (functionInput[i] == 'c'){
									checkVar = checkVar + 1;
									varSetup = c;
								}
								else if (functionInput[i] == 'd'){
									checkVar = checkVar + 1;
									varSetup = d;
								}
								else if (functionInput[i] == '!'){
									varNOT = 1;
								}
								else if (functionInput[i] == '&'){
									varAND = 1;
									checkOperand = checkOperand + 1;
								}
								else if (functionInput[i] == '|'){
									varOR = 1;
									checkOperand = checkOperand + 1;
								}
								else if (functionInput[i] == '^'){
									varXOR = 1;
									checkOperand = checkOperand + 1;
								}
								else if (functionInput[i] == '('){
									functionOrder = functionOrder + 1;
									if (functionOrder == 1){
										varNOT1 = varNOT;
										varAND1 = varAND;
										varOR1 = varOR;
										varXOR1 = varXOR;
									}
									else if (functionOrder == 2){
										varNOT2 = varNOT;
										varAND2 = varAND;
										varOR2 = varOR;
										varXOR2 = varXOR;
									}
									else if (functionOrder == 3){
										varNOT3 = varNOT;
										varAND3 = varAND;
										varOR3 = varOR;
										varXOR3 = varXOR;
									}
									else if (functionOrder == 4){
										varNOT4 = varNOT;
										varAND4 = varAND;
										varOR4 = varOR;
										varXOR4 = varXOR;
									}
									else{
										printf("ERROR: CHECK PARENTHESIS, ENDING PROGRAM...\n");
										return 0;
									}
									checkOperand = 0;
									varNOT = 0;
									varAND = 0;
									varOR = 0;
									varXOR = 0;
								}
								else if (functionInput[i] == ')'){
									if (functionOrder == 1){
										if (startFunction == 1){
											if (varNOT1 == 1){
												function1 = !function1;
												varNOT1 = 0;
											}
											if (varAND1 == 1){
												function1 = functionFinal & function1;
												varAND1 = 0;
											}
											else if (varOR1 == 1){
												function1 = functionFinal | function1;
												varOR1 = 0;
											}
											else if (varXOR1 == 1){
												function1 = functionFinal ^ function1;
												varXOR1 = 0;
											}
											functionFinal = function1;
										}
										else{
											if (varNOT1 == 1){
												function1 = !function1;
												varNOT1 = 0;
											}
											startFunction = 1;
											functionFinal = function1;
										}
									}
									else if (functionOrder == 2){
										if (varNOT2 == 1){
											function2 = !function2;
											varNOT2 = 0;
										}
										if (varAND2 == 1){
											function2 = function1 & function2;
											varAND2 = 0;
										}
										else if (varOR2 == 1){
											function2 = function1 | function2;
											varOR2 = 0;
										}
										else if (varXOR2 == 1){
											function2 = function1 ^ function2;
											varXOR2 = 0;
										}
										function1 = function2;
									}
									else if (functionOrder == 3){
										if (varNOT3 == 1){
											function3 = !function3;
											varNOT3 = 0;
										}
										if (varAND3 == 1){
											function3 = function2 & function3;
											varAND3 = 0;
										}
										else if (varOR3 == 1){
											function3 = function2 | function3;
											varOR3 = 0;
										}
										else if (varXOR3 == 1){
											function3 = function2 ^ function3;
											varXOR3 = 0;
										}
										function2 = function3;
									}
									else if (functionOrder == 4){
										if (varNOT4 == 1){
											function4 = !function4;
											varNOT4 = 0;
										}
										if (varAND4 == 1){
											function4 = function3 & function4;
											varAND4 = 0;
										}
										else if (varOR4 == 1){
											function4 = function3 | function4;
											varOR4 = 0;
										}
										else if (varXOR4 == 1){
											function4 = function3 ^ function4;
											varXOR4 = 0;
										}
										function3 = function4;
									}
									else{
										printf("ERROR: CHECK PARENTHESIS, ENDING PROGRAM...\n");
										return 0;
									}
									functionOrder = functionOrder - 1;
								}
								else{
									printf("ERROR: NOT A VALID ENTRY, ENDING PROGRAM...\n");
									return 0;
								}
								if (checkVar > 1){
									printf("ERROR: CHECK VARIABLES, ENDING PROGRAM...\n");
									return 0;
								}
								if (checkOperand > 1){
									printf("ERROR: CHECK OPERANDS, ENDING PROGRAM...\n");
									return 0;
								}
								if (functionInput[i] == '(' && functionInput[i+1] == ')'){
									printf("ERROR: CHECK PARENTHESIS, ENDING PROGRAM...\n");
									return 0;
								}
								if (checkVar == 1){
									if (functionOrder == 0){
										if (varNOT == 1){
											varSetup = !varSetup;
											varNOT = 0;
										}
										if (varAND == 1){
											varSetup = functionFinal & varSetup;
											varAND = 0;
										}
										else if (varOR == 1){
											varSetup = functionFinal | varSetup;
											varOR = 0;
										}
										else if (varXOR == 1){
											varSetup = functionFinal ^ varSetup;
											varXOR = 0;
										}
										functionFinal = varSetup;
									}
									else if (functionOrder == 1){
										if (varNOT == 1){
											varSetup = !varSetup;
											varNOT = 0;
										}
										if (varAND == 1){
											varSetup = function1 & varSetup;
											varAND = 0;
										}
										else if (varOR == 1){
											varSetup = function1 | varSetup;
											varOR = 0;
										}
										else if (varXOR == 1){
											varSetup = function1 ^ varSetup;
											varXOR = 0;
										}
										function1 = varSetup;
									}
									else if (functionOrder == 2){
										if (varNOT == 1){
											varSetup = !varSetup;
											varNOT = 0;
										}
										if (varAND == 1){
											varSetup = function2 & varSetup;
											varAND = 0;
										}
										else if (varOR == 1){
											varSetup = function2 | varSetup;
											varOR = 0;
										}
										else if (varXOR == 1){
											varSetup = function2 ^ varSetup;
											varXOR = 0;
										}
										function2 = varSetup;
									}
									else if (functionOrder == 3){
										if (varNOT == 1){
											varSetup = !varSetup;
											varNOT = 0;
										}
										if (varAND == 1){
											varSetup = function3 & varSetup;
											varAND = 0;
										}
										else if (varOR == 1){
											varSetup = function3 | varSetup;
											varOR = 0;
										}
										else if (varXOR == 1){
											varSetup = function3 ^ varSetup;
											varXOR = 0;
										}
										function3 = varSetup;
									}
									else if (functionOrder == 4){
										if (varNOT == 1){
											varSetup = !varSetup;
											varNOT = 0;
										}
										if (varAND == 1){
											varSetup = function4 & varSetup;
											varAND = 0;
										}
										else if (varOR == 1){
											varSetup = function4 | varSetup;
											varOR = 0;
										}
										else if (varXOR == 1){
											varSetup = function4 ^ varSetup;
											varXOR = 0;
										}
										function4 = varSetup;
									}
									checkOperand = 0;
									checkVar = 0;
								}
							}
							printf("  %d  %d  %d  %d |  %d  \n", a, b, c, d, functionFinal);
							if (functionFinal == 1){
								functionOutput[outCheck] = '1';
							}
							else{
								functionOutput[outCheck] = '0';
							}
							outCheck = outCheck + 1;
						}
					}
				}
			}
			printf("-------------|-----\n");
			printf("\n");
			printf("\n");
			printf("K-Map:\n");
			printf("                    CD\n");
			printf("          0 0   0 1   1 1   1 0\n");
			printf("        |-----|-----|-----|-----|\n");
			printf("    0 0 |  %c  |  %c  |  %c  |  %c  |\n", functionOutput[1], functionOutput[2], functionOutput[4], functionOutput[3]);
			printf("        |-----|-----|-----|-----|\n");
			printf("    0 1 |  %c  |  %c  |  %c  |  %c  |\n", functionOutput[5], functionOutput[6], functionOutput[8], functionOutput[7]);
			printf(" AB     |-----|-----|-----|-----|\n");
			printf("    1 1 |  %c  |  %c  |  %c  |  %c  |\n", functionOutput[13], functionOutput[14], functionOutput[16], functionOutput[15]);
			printf("        |-----|-----|-----|-----|\n");
			printf("    1 0 |  %c  |  %c  |  %c  |  %c  |\n", functionOutput[9], functionOutput[10], functionOutput[12], functionOutput[11]);
			printf("        |-----|-----|-----|-----|\n");
		}
		else{
			printf("ERROR: NOT A VALID ENTRY, ENDING PROGRAM...\n");
			return 0;
		}
		memset(functionOutput,0,32);
		memset(functionInput,0,32);
		printf("\n");
		printf("\n");
		printf("Exit Program? (0-Exit, 1-TryAgain): ");
		scanf("%d", &x);
		if (x!=0&&x!=1){
			printf("ERROR: NOT A VALID ENTRY, ENDING PROGRAM...\n");
			return 0;
		}
		else if (x == 0){
			printf("Ending Program...\n");
		}
		printf("\n");
		printf("\n");
	}while(x==1);
	return 0;
}
