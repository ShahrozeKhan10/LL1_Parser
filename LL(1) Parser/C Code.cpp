#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string.h>

#include <stdio.h>
#include <cstring>

using namespace std;
int ttlTokens=0,ttloper=0;
int ttlarth=0,ttlsep=0,ttlrel=0,ttllog=0,ttlbit=0,ttlassi=0,ttlif=0,ttlelse=0,ttlswitch=0,ttlcase=0,ttlbreak=0,ttlint=0,ttldeci=0,ttlstring=0,ttlvoid=0,ttlfor=0,ttlwhile=0,ttldo=0,ttlreturn=0,ttlcin=0,ttlcout=0;
int dfa = 0;
int intpass,ifpass,casepass,cinpass,coutpass,switchpass,stringpass,breakpass,dopass,decipass;

// ---------------------I--------------------------------Start
void i_start(char X) {

	if (X == 'i') {
		dfa = 1;

	} else {
		dfa = -1;

	}
}

void i_state1(char X) 
{
	if (X == 'n') 
	{
		dfa = 2;

	} else if (X == 'f')
	{
		dfa=3;
		ifpass=1;
		
	} else 
	{
		dfa = -1;

	}
}

void i_state2(char X) {
	

	if (X == 't') {
		
		dfa = 3;
		intpass=1;
		
	} else {
		dfa = -1;

	}
}

void i_state3(char X) {

	dfa = -1;
}


int i_isAccepted(string str) {
	
	int i,len=str.length();

	for (i = 0; i < len; i++) {

		if (dfa == 0) i_start(str[i]);

		else if (dfa == 1) i_state1(str[i]);

		else if (dfa == 2) i_state2(str[i]);

		else if (dfa == 3) i_state3(str[i]);


		else
			return 0;
	}

	if (dfa == 3) return 1;
	else
		return 0;

}

// ---------------------I--------------------------------End


// ---------------------E--------------------------------Start
void e_start(char X) {

	if (X == 'e') {
		dfa = 1;

	} else {
		dfa = -1;

	}
}

void e_state1(char X) 
{
	if (X == 'l') 
	{
		dfa = 2;

	} else 
	{
		dfa = -1;

	}
}

void e_state2(char X) {
	

	if (X == 's') {
		
		dfa = 3;
		
	} else {
		dfa = -1;

	}
}

void e_state3(char X) {

	if (X == 'e') {
		
		dfa = 4;
		
	} else {
		dfa = -1;

	}
}

void e_state4(char X) {

	dfa = -1;
}



int e_isAccepted(string str) {
	
	int i,len=str.length();

	for (i = 0; i < len; i++) 
	{
		if (dfa == 0) e_start(str[i]);

		else if (dfa == 1) e_state1(str[i]);

		else if (dfa == 2) e_state2(str[i]);

		else if (dfa == 3) e_state3(str[i]);
		
		else if (dfa == 4) e_state4(str[i]);



		else
			return 0;
	}

	if (dfa == 4) return 1;
	else
		return 0;

}

// ---------------------E--------------------------------End


// ---------------------C--------------------------------Start
void c_start(char X) {

	if (X == 'c') {
		dfa = 1;

	} else {
		dfa = -1;

	}
}

void c_state1(char X) 
{
	if (X == 'a') 
	{
		dfa = 2;

	} else if (X == 'o')
	{
		dfa=2;
		
	}else if (X == 'i')
	{
		dfa=2;
		
	} else 
	{
		dfa = -1;

	}
}

void c_state2(char X) {
	

	if (X == 's'){
		
		dfa=3;
		
	} 
	else if (X == 'u'){
		dfa=3;
		
	}
	else if (X == 'n'){
		cinpass=1;
		dfa=4;
		
	} 
	else {
		dfa = -1;

	}
}

void c_state3(char X) {
	

	if (X == 'e') {
		
		dfa=4;
		casepass=1;
		
	} else if (X == 't')
	{
		dfa=4;
		coutpass=1;
		
	} else {
		dfa = -1;

	}
}

void c_state4(char X) {

	dfa = -1;
}


int c_isAccepted(string str) {
	
	int i,len=str.length();

	for (i = 0; i < len; i++) 
	{
		if (dfa == 0) c_start(str[i]);

		else if (dfa == 1) c_state1(str[i]);

		else if (dfa == 2) c_state2(str[i]);

		else if (dfa == 3) c_state3(str[i]);
		
		else if (dfa == 4) c_state4(str[i]);


		else
			return 0;
	}

	if (dfa == 4) return 1;
	else
		return 0;

}

// ---------------------c--------------------------------End


// ---------------------S--------------------------------Start
void s_start(char X) {

	if (X == 's') {
		dfa = 1;

	} else {
		dfa = -1;

	}
}

void s_state1(char X) 
{
	if (X == 'w') {
		dfa = 2;

	} 
	else if (X == 't'){
		dfa=2;
		
	}
	else {
		dfa = -1;

	}
}

void s_state2(char X) {
	

	if (X == 'i'){
		
		dfa=3;
		
	} 
	else if (X == 'r'){
		dfa=3;
		
	}
	else {
		dfa = -1;

	}
}

void s_state3(char X) {
	

	if (X == 't') {
		
		dfa=4;
		
	} else if (X == 'i')
	{
		dfa=4;
		
	} else {
		dfa = -1;

	}
}

void s_state4(char X) {
	

	if (X == 'c'){
		
		dfa=5;
		
	} 
	else if (X == 'n'){
		dfa=5;
		
	}
	else {
		dfa = -1;

	}
}

void s_state5(char X) {
	

	if (X == 'h') {
		
		dfa=6;
		switchpass=1;
		
	} else if (X == 'g')
	{
		dfa=6;
		stringpass=1;
		
	} else {
		dfa = -1;

	}
}
void s_state6(char X) {

	dfa = -1;
}


int s_isAccepted(string str) {
	
	int i,len=str.length();

	for (i = 0; i < len; i++) 
	{
		if (dfa == 0) s_start(str[i]);

		else if (dfa == 1) s_state1(str[i]);

		else if (dfa == 2) s_state2(str[i]);

		else if (dfa == 3) s_state3(str[i]);
		
		else if (dfa == 4) s_state4(str[i]);
		
		else if (dfa == 5) s_state5(str[i]);
		
		else if (dfa == 6) s_state6(str[i]);


		else
			return 0;
	}

	if (dfa == 6) return 1;
	else
		return 0;

}

// ---------------------S--------------------------------End

// ---------------------B--------------------------------Start
void b_start(char X) {

	if (X == 'b') {
		dfa = 1;

	} else {
		dfa = -1;

	}
}

void b_state1(char X) 
{
	if (X == 'r') {
		dfa = 2;

	} else {
		dfa = -1;

	}
}

void b_state2(char X) {
	

	if (X == 'e'){
		
		dfa=3;
		
	} 
	else {
		dfa = -1;

	}
}

void b_state3(char X) {
	

	if (X == 'a') {
		
		dfa=4;
		
	}  else {
		dfa = -1;

	}
}

void b_state4(char X) {
	

	if (X == 'k'){
		
		dfa=5;
		
	} else {
		dfa = -1;

	}
}

void b_state5(char X) {

	dfa = -1;
}


int b_isAccepted(string str) {
	
	int i,len=str.length();

	for (i = 0; i < len; i++) 
	{
		if (dfa == 0) b_start(str[i]);

		else if (dfa == 1) b_state1(str[i]);

		else if (dfa == 2) b_state2(str[i]);

		else if (dfa == 3) b_state3(str[i]);
		
		else if (dfa == 4) b_state4(str[i]);
		
		else if (dfa == 5) b_state5(str[i]);
		
		else
			return 0;
	}

	if (dfa == 5) return 1;
	else
		return 0;

}

// ---------------------B--------------------------------End

// ---------------------D--------------------------------Start
void d_start(char X) {

	if (X == 'd') {
		dfa = 1;

	} else {
		dfa = -1;

	}
}

void d_state1(char X) 
{
	if (X == 'e') {
		dfa = 2;

	} else if (X == 'o') {
		dfa=4;
		dopass=0;
		
	} else {
		dfa = -1;

	}
}

void d_state2(char X) {
	

	if (X == 'c'){
		
		dfa=3;
		
	} 
	else {
		dfa = -1;

	}
}

void d_state3(char X) {
	

	if (X == 'i') {
		
		dfa=4;
		decipass=1;
		
	}  else {
		dfa = -1;

	}
}



void d_state4(char X) {

	dfa = -1;
}


int d_isAccepted(string str) {
	
	int i,len=str.length();

	for (i = 0; i < len; i++) 
	{
		if (dfa == 0) d_start(str[i]);

		else if (dfa == 1) d_state1(str[i]);

		else if (dfa == 2) d_state2(str[i]);

		else if (dfa == 3) d_state3(str[i]);
		
		else if (dfa == 4) d_state4(str[i]);

		
		else
			return 0;
	}

	if (dfa == 4) {return 1;}
	else
		return 0;

}

// ---------------------D--------------------------------End

// ---------------------F--------------------------------Start
void f_start(char X) {

	if (X == 'f') {
		dfa = 1;

	} else {
		dfa = -1;

	}
}

void f_state1(char X) 
{
	if (X == 'o') {
		dfa = 2;

	} else {
		dfa = -1;

	}
}

void f_state2(char X) {
	

	if (X == 'r'){
		
		dfa=3;
		
	} 
	else {
		dfa = -1;

	}
}

void f_state3(char X) {

	dfa = -1;
}


int f_isAccepted(string str) {
	
	int i,len=str.length();

	for (i = 0; i < len; i++) 
	{
		if (dfa == 0) f_start(str[i]);

		else if (dfa == 1) f_state1(str[i]);

		else if (dfa == 2) f_state2(str[i]);

		else if (dfa == 3) f_state3(str[i]);
		
		else
			return 0;
	}

	if (dfa == 3) return 1;
	else
		return 0;

}

// ---------------------F--------------------------------End

// ---------------------V--------------------------------Start
void v_start(char X) {

	if (X == 'v') {
		dfa = 1;

	} else {
		dfa = -1;

	}
}

void v_state1(char X) 
{
	if (X == 'o') {
		dfa = 2;

	} else {
		dfa = -1;

	}
}

void v_state2(char X) {
	

	if (X == 'i'){
		
		dfa=3;
		
	} 
	else {
		dfa = -1;

	}
}

void v_state3(char X) {
	

	if (X == 'd') {
		
		dfa=4;
		
	}  else {
		dfa = -1;

	}
}

void v_state4(char X) {

	dfa = -1;
}


int v_isAccepted(string str) {
	
	int i,len=str.length();

	for (i = 0; i < len; i++) 
	{
		if (dfa == 0) v_start(str[i]);

		else if (dfa == 1) v_state1(str[i]);

		else if (dfa == 2) v_state2(str[i]);

		else if (dfa == 3) v_state3(str[i]);
		
		else if (dfa == 4) v_state4(str[i]);

		
		else
			return 0;
	}

	if (dfa == 4) return 1;
	else
		return 0;

}

// ---------------------V--------------------------------End

// ---------------------W--------------------------------Start
void w_start(char X) {

	if (X == 'w') {
		dfa = 1;

	} else {
		dfa = -1;

	}
}

void w_state1(char X) 
{
	if (X == 'h') {
		dfa = 2;

	} else {
		dfa = -1;

	}
}

void w_state2(char X) {

	dfa = -1;
}


int w_isAccepted(string str) {
	
	int i,len=str.length();

	for (i = 0; i < len; i++) 
	{
		if (dfa == 0) w_start(str[i]);

		else if (dfa == 1) w_state1(str[i]);

		else if (dfa == 2) w_state2(str[i]);
		
		else
			return 0;
	}

	if (dfa == 2) return 1;
	else
		return 0;

}

// ---------------------W--------------------------------End

// ---------------------R--------------------------------Start
void r_start(char X) {

	if (X == 'r') {
		dfa = 1;

	} else {
		dfa = -1;

	}
}

void r_state1(char X) 
{
	if (X == 'e') {
		dfa = 2;

	} else {
		dfa = -1;

	}
}

void r_state2(char X) 
{
	if (X == 't') {
		dfa = 3;

	} else {
		dfa = -1;

	}
}

void r_state3(char X) {

	dfa = -1;
}


int r_isAccepted(string str) {
	
	int i,len=str.length();

	for (i = 0; i < len; i++) 
	{
		if (dfa == 0) r_start(str[i]);

		else if (dfa == 1) r_state1(str[i]);

		else if (dfa == 2) r_state2(str[i]);
		
		else if (dfa == 3) r_state3(str[i]);
		
		else
			return 0;
	}

	if (dfa == 3) return 1;
	else
		return 0;

}

// ---------------------R--------------------------------End

int main() {
	ofstream DataFile;
	DataFile.open("tokensDataC++.txt");
	DataFile << "";

	ifstream CodeFile("Testing Code.txt");



	if (CodeFile.is_open()) {

		DataFile << "\t\tExpresssion \t Tokens \n\n";
		string str;
		char ch;

		int i=0;
		DataFile << "\t\t-----------------------------------------\n";
		if (DataFile.is_open()) 
		{
			while (CodeFile.get(ch)) 
			{
				if( ch ==' ' || ch == '\n' || ch == '\t') 
				{
					if (str[0] == 'i') 
					{
						
						if (i_isAccepted(str)) 
						{
							dfa=0;
							if(ifpass==1)
							{
								DataFile << "\t\t|\tif \t|\t if_Condition\t|\n";
								DataFile << "\t\t-----------------------------------------\n";
								ttlif++;
								ttlTokens++;
								ifpass=0;
							}
							else
							{
								DataFile << "\t\t|\tint \t|\t int_DataType\t|\n";
								DataFile << "\t\t-----------------------------------------\n";
								ttlint++;
								ttlTokens++;
								intpass=0;
							}
						} 
						else 
						{
							dfa=0;
						}
					} 
					else if (str[0] == 'e') {
						if (e_isAccepted(str)) 
						{
							dfa=0;
							DataFile << "\t\t|\telse \t|\t else_Condition\t|\n";
							DataFile << "\t\t-----------------------------------------\n";
							ttlelse++;	
							ttlTokens++;
						} 
						else 
						{
							dfa=0;
						}

					} else if (str[0] == 'c') {
						if (c_isAccepted(str)) 
						{
							dfa=0;
							if(casepass==1)
							{
								DataFile << "\t\t|\tcase \t|\t case_Condition\t|\n";
								DataFile << "\t\t-----------------------------------------\n";
								ttlcase++;	
								ttlTokens++;
								casepass=0;
							}
							else if(coutpass==1)
							{
								DataFile << "\t\t|\tcout \t|\t print_Data\t|\n";
								DataFile << "\t\t-----------------------------------------\n";
								ttlcout++;	
								ttlTokens++;
								coutpass=0;
							}
							else
							{
								DataFile << "\t\t|\tcin \t|\t get_Data\t|\n";
								DataFile << "\t\t-----------------------------------------\n";
								ttlcin++;
								ttlTokens++;
								cinpass=0;
							}
						} 
						else 
						{
							dfa=0;
						}

					} else if (str[0] == 's') {
						if (s_isAccepted(str)) 
						{
							dfa=0;
							if(switchpass==1)
							{
								DataFile << "\t\t|\tswitch\t|\t switch_Case\t|\n";
								DataFile << "\t\t-----------------------------------------\n";
								ttlswitch++;
								ttlTokens++;	
								switchpass=0;
							}
							else
							{
								DataFile << "\t\t|\tstring\t|\t string_DataType|\n";
								DataFile << "\t\t-----------------------------------------\n";
								ttlstring++;
								ttlTokens++;	
								stringpass=0;
							}
						} 
						else 
						{
							dfa=0;
						}
					} else if (str[0] == 'b') {
						if (b_isAccepted(str)) 
						{
							dfa=0;
							DataFile << "\t\t|\tbreak \t|\t Stop_Condition\t|\n";
							DataFile << "\t\t-----------------------------------------\n";
							ttlbreak++;	
							ttlTokens++;
						} 
						else 
						{
							dfa=0;
						}

					} else if (str[0] == 'd') {
						if (d_isAccepted(str)) 
						{
							dfa=0;
							if(decipass==1)
							{
								DataFile << "\t\t|\tdeci \t|\t deci_DataType\t|\n";
								DataFile << "\t\t-----------------------------------------\n";
								ttldeci++;	
								ttlTokens++;
								decipass=0;
								
							}
							else
							{
								DataFile << "\t\t|\tdo \t|\t Do_Loop\t|\n";
								DataFile << "\t\t-----------------------------------------\n";
								ttldo++;	
								ttlTokens++;
								dopass=0;
							}
						
						} 
						else 
						{
							dfa=0;
						}

					} else if (str[0] == 'f') {
						if (f_isAccepted(str)) 
						{
							dfa=0;
							DataFile << "\t\t|\tfor \t|\t for_Loop\t|\n";
							DataFile << "\t\t-----------------------------------------\n";
							ttlfor++;
							ttlTokens++;
						} 
						else 
						{
							dfa=0;
						}

					} else if (str[0] == 'v') {
						if (v_isAccepted(str)) 
						{
							dfa=0;
							DataFile << "\t\t|\tvoid \t|\t void_Func\t|\n";
							DataFile << "\t\t-----------------------------------------\n";
							ttlvoid++;	
							ttlTokens++;
						} 
						else 
						{
							dfa=0;
						}

					} else if (str[0] == 'w') {
						if (w_isAccepted(str)) 
						{
							dfa=0;
							DataFile << "\t\t|\twhile \t|\t while_Condition|\n";
							DataFile << "\t\t-----------------------------------------\n";
							ttlwhile++;	
							ttlTokens++;
						} 
						else 
						{
							dfa=0;
						}

					} else if (str[0] == 'r') {
					if (r_isAccepted(str)) 
						{
							dfa=0;
							DataFile << "\t\t|\treturn \t|\t return_kword\t|\n";
							DataFile << "\t\t-----------------------------------------\n";
							ttlreturn++;
							ttlTokens++;
						} 
						else 
						{
							dfa=0;
						}

					} else if (str == "(" || str == ")" || str == "{" || str == "}" || str == ":" || str == ",")
					{
						DataFile << "\t\t|\t"<<str<<" \t|\t Arithmetic Op\t|\n";
						DataFile << "\t\t-----------------------------------------\n";
						ttlarth++;
						ttloper++;
					}	
					else if(str == "+" || str == "-" || str == "*" || str == "/" || str == "%")
					{
						DataFile << "\t\t|\t"<<str<<" \t|\t Separator op\t|\n";
						DataFile << "\t\t-----------------------------------------\n";
						ttlsep++;
						ttloper++;
					}
					else if(str == "<" || str == "<=" || str == ">" || str == ">=" || str == "==" || str == "!=")
					{
						DataFile << "\t\t|\t"<<str<<" \t|\t Relational Op\t|\n";
						DataFile << "\t\t-----------------------------------------\n";
						ttlrel++;
						ttloper++;
					}
					else if(str == "!" || str == "||" || str == "&&")
					{
						DataFile << "\t\t|\t"<<str<<" \t|\t Logical Op\t|\n";
						DataFile << "\t\t-----------------------------------------\n";
						ttllog++;
						ttloper++;
					}
					else if(str == "^" || str == "&" || str == ">>" || str == "~" || str == "|" || str == "<<")
					{
						DataFile << "\t\t|\t"<<str<<" \t|\t Bitwise Op\t|\n";
						DataFile << "\t\t-----------------------------------------\n";
						ttlbit++;
						ttloper++;
					}
					else if(str == "=" || str == "+=" || str == "-=" || str == "*=" || str == "/=" || str == "%=")
					{
						DataFile << "\t\t|\t"<<str<<" \t|\t Assignment Op\t|\n";
						DataFile << "\t\t-----------------------------------------\n";
						ttlassi++;
						ttloper++;
					}
					else {
					}
					str="";
				} else {
					str +=ch;
				}
			}



			DataFile << "\n\n\t\tTotal Tokens \n";
			if ( ttlif > 0 ) DataFile << "Total if = "<<  ttlif<< " \n";
			if ( ttlelse > 0 ) DataFile << "Total else = "<< ttlelse<< " \n";
			if ( ttlswitch > 0 ) DataFile << "Total switch = "<< ttlswitch<< " \n";
			if ( ttlcase > 0 ) DataFile << "Total case = "<< ttlcase<< " \n";
			if ( ttlbreak > 0 ) DataFile << "Total break = "<< ttlbreak<< " \n";
			if ( ttlint > 0 ) DataFile << "Total int = " <<ttlint<< " \n";
			if ( ttldeci > 0 ) DataFile << "Total deci = " <<ttldeci<< " \n";
			if ( ttlstring > 0 ) DataFile << "Total string = " << ttlstring<< " \n";
			if ( ttlvoid > 0 ) DataFile << "Total void = " <<ttlvoid<< " \n";
			if ( ttlfor > 0 ) DataFile << "Total for = " <<ttlfor<< " \n";
			if ( ttlwhile > 0 ) DataFile << "Total while = " <<ttlwhile<< " \n";
			if ( ttldo > 0 ) DataFile << "Total do = " << ttldo << " \n";
			if ( ttlreturn > 0 ) DataFile << "Total return = " <<ttlreturn<< " \n";
			if ( ttlcin > 0 ) DataFile << "Total cin = " <<ttlcin<< " \n";
			if ( ttlcout > 0 ) DataFile << "Total cout = " <<ttlcout<< " \n";
			DataFile << "\nTotal Tokens = " <<ttlTokens<<" \n\n";


			DataFile << "\n\n\t\tTotal Operations \n";
			if ( ttlarth > 0 ) DataFile << "Total Arithmetic = " <<ttlarth<< " \n";
			if ( ttlsep > 0 ) DataFile << "Total Separator = " <<ttlsep<< " \n";
			if ( ttlrel > 0 ) DataFile << "Total Relational = " << ttlrel << " \n";
			if ( ttllog > 0 ) DataFile << "Total Logical = " <<ttllog<< " \n";
			if ( ttlbit > 0 ) DataFile << "Total Bitwise = " <<ttlbit<< " \n";
			if ( ttlassi > 0 ) DataFile << "Total Assignment = " <<ttlassi<< " \n";
			DataFile << "\nTotal Tokens = " <<ttloper<<" \n\n";

		} else {
			cout << "Error opening file." << endl;
		}
		DataFile.close();

		CodeFile.close();
	} else {
		cout << "Test Code File Can't Find" << endl;

	}

	ifstream dataFile1("tokensDataC++.txt"); 
    string linetwo;
    if (dataFile1.is_open()) {
        while (std::getline(dataFile1, linetwo)) { 
            cout << linetwo << endl; 
        }
        dataFile1.close();
    } else {
        cout << "Unable to open file" << std::endl;
    }

	return 0;


}
