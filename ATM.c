#include <stdio.h>
#include <stdlib.h>
#include "ATMLibrary.h"

int main () {

	int makbuzSecim;//makbuz isteyip istemediðini sorgulamak için obje tanýmladýk.
	int islem;//ana menüde yapmak istediði iþlemi sorgulamak için obje tanýmladýk.
	int secim=1;//baþka bir iþlem yapýp yapmayacaðýný sorgulamak için obje tanýmladýk.
	makbuz=fopen("makbuz.txt","w");
	fclose(makbuz);
	struct yeniuye s;//struct objemizi tanýmladýk.
	struct yeniuye *ptr;//struct objemizi pointer olarak tanýmladýk.
	ptr=&s;//adresi pointera atadýk.

	Yeniuyelik(s,ptr);//Yeni üyelik için fonksiyonu cagirdik.
	
	Giris(s,ptr);//Giriþ için fonksiyon çaðýrdýk.

	printf("\n\n\t\t\t\t\t\t\tMakbuz ister misiniz?\n\t\t\t\t\t\t\t[1]Evet\n\t\t\t\t\t\t\t[2]Hayir\n");
	scanf("%d",&makbuzSecim);
		
	while(islem=2) {
			
	
	printf("\t\t\t\t\tATM Islemleri\n\n\t\t\t\t\t[1]Para Cekme\n\n\t\t\t\t\t[2]Para Yatirma\n\n\t\t\t\t\t[3]Havale Yapma\n\n\t\t\t\t\t[4]Bakiye Sorgulama\n\n\t\t\t\t\t[5]Fatura Odeme\n\n\t\t\t\t\t[6]Doviz Alim-Satimi\n\n\t\t\t\t\t[7]Kredi Talebi\n\n\t\t\t\t\t[8]Kart Iade\n\n\n");
	
	printf("\t\t\t\t\tLutfen Yapacaginiz Islemin Rakamini Tuslayiniz: ");
	scanf("%d",&islem);
	
	
		switch(islem) {
		
			case 1 :
				makbuz=fopen("makbuz.txt","a+");
				paracekme(s,ptr,makbuz);
				fclose(makbuz);
				break;		
		
			case 2 : 
				makbuz=fopen("makbuz.txt","a+");
				parayatirma(s,ptr,makbuz);
				fclose(makbuz);
				break;		
				
			case 3 :
					makbuz=fopen("makbuz.txt","a+");
				havaleyapma(s,ptr,makbuz);
				fclose(makbuz);				
				break;
		
			case 4 :
					makbuz=fopen("makbuz.txt","a+");
				bakiyesorgulama(s,ptr,makbuz);
				fclose(makbuz);
				break;
		
		
			case 5 :
					makbuz=fopen("makbuz.txt","a+");
				faturaodeme(s,ptr,makbuz);
				fclose(makbuz);
				break;
			case 6:
					makbuz=fopen("makbuz.txt","a+");
				Doviz(s,ptr,makbuz);
				fclose(makbuz);
				break;
			case 7 :
					makbuz=fopen("makbuz.txt","a+");
				KrediTalep(s,ptr,makbuz);
				fclose(makbuz);
				break;
			case 8 :
		
			printf("\n\n\n\t\t\t\t\tKARTINIZI ALMAYI UNUTMAYIN !!! \n\n\n\n\n\n\t\t\t\t\tBizi Sectiginiz Icin Tesekkur Eder Iyi Gunler Dileriz.\n\n\n\n\n\t\t\t\t\tINCIBANK\n\n\n\n");		
			return 0;
			
	
			
		default : 
		printf("\n\n\n\t\t\t\t\t\aYanlis Kodlama Yaptiniz. Tekrar Deneyiniz...");	
		break;		

	}

	 printf("\n\n\n\t\t\t\t\tBaska bir islem yapmak istiyor musunuz ?\n\t\t\t\t\t[1]Evet\n\t\t\t\t\t[2]Hayir\n\n");
	scanf("%d",&secim);
	if(secim==2) {
		printf("\n\n\n\t\t\t\t\tKARTINIZI ALMAYI UNUTMAYIN !!! \n\n\n\t\t\t\t\tBizi sectiginiz icin tesekkur eder iyi gunler dileriz.\n\n\n\n\t\t\t\t\tINCIBANK\n\n\n\n"); 
	
	
	break;
	}

}

if(makbuzSecim==1){
makbuz=fopen("makbuz.txt","r");
makbuzYazdir(makbuz,s,ptr);
fclose(makbuz);

}
return 0;
}
