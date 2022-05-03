#include"ATMLibrary.h"



void Yeniuyelik(struct yeniuye s, struct yeniuye *ptr){
	printf("\n\n\n\t\t\t\t\t\t  INCI BANK'A HOSGELDINIZ\n");	
	printf("\n\t\t\t\t\t\tYENI VADESIZ HESAP ACILISI\n ");
	printf("\n\t\t\t\t\tLutfen 11 haneli TC kimlik numaranizi giriniz:");
	scanf("%llu",&ptr->TcNo);//tc no yu aldýk.
	
	printf("\n\t\t\t\t\tLutfen yeni sifrenizi giriniz:");
	scanf("%d",&ptr->sifre);//sifreyi aldýk.


	printf("\n\t\t\t\t\t**************************************");
	printf("\n\n\t\t\t\t\tGiris Ekranina Yonlendiriliyorsunuz...\n\n");
	printf("\t\t\t\t\t**************************************");		
}

void Giris(struct yeniuye s, struct yeniuye *ptr){
	int matris[3][3] = {{1,2,3},{4,5,6},{7,8,9}};//tus ekranini tanimladýk.
	int i,j,k,l=0;
	int count=0;//hatayý kontrol etmek için bir obje tanýmladýk.
	ptr=&s;//adresi pointera atadýk.
	unsigned long long int Tcdogrulama;
	int sifredogrulama;
	
		
	printf("\n\n\n\t\t\t\t\t\tINCI BANK'A HOSGELDINIZ\n");	
	while(l<3) {//while döngüsünü çaðýrdýk.
	
	printf("\n\n\n\n\t\t\t\t\t\t%d deneme hakkiniz kaldi!\n\n\n\n\n\n",3 - count);

	for(i=0;i<3; i++){

	printf("\n\n\t\t\t\t\t\t\t");

		for(j=0; j<3; j++) {
	
		printf("%d  ",matris[i][j]);//tuþ ekranýný bastýk
	}
}
	printf("\n\n\n\t\t\t\t\t\tTC kimlik numaranizi giriniz: ");
	scanf("%llu",&Tcdogrulama);//Giriþ ekranýnda tc'yi aldýk.
	
	
		printf("\n\n\n\t\t\t\t\t\tSifrenizi giriniz: ");
		scanf("%d",&sifredogrulama);//Giriþ ekranýnda sifreyi aldýk
		
		if (sifredogrulama == ptr->sifre && Tcdogrulama == ptr->TcNo) {//TC ve sifrenin dogruluðunu tespit ediyoruz.
			printf("\n\t\t\t\t\t     **************************************");
			printf("\n\n\t\t\t\t\t\t\tGIRIS BASARILI\n\n");
			printf("\t\t\t\t\t     **************************************");
		break;
	}
		else{
			printf("\n\n\t\t\t\t\aTC Kimlik Numaranizi Veya Sifreyi Yanlis Girdiniz.Tekrar Deneyiniz.\n\n");
			}
			count++;
	
		 if (count == 3) {
			printf("\t\t\t\t\t\aKartiniz Bloke Olmustur. Lutfen Bankanizla Irtibata Geciniz !\n\n\n");//3 kere yanlýþ girilirse proðramý bitir.
			exit(0);
		}
	l++;
	}
}

void paracekme(struct yeniuye s, struct yeniuye *ptr,FILE* makbuz){
			double tutar;//çekilecek tutarý öðrenmek için obje tanýmlýyoruz.
			
			printf("\n\n\n\t\t\t\t\tbakiyeniz: %.2lf TL\n\n",ptr->bakiye);
			printf("\n\n\n\t\t\t\t\tCekeceginiz tutari giriniz: ");
			scanf("%lf",&tutar);//cekilecek tutari alýyoruz.
			
			if (tutar>ptr->bakiye) {//bakiye ve tutarý karþýlaþtýrýyoruz.
				printf("\n\n\n\t\t\t\t\tBakiyeniz yetersizdir.Tekrar Deneyiniz.");
				}
			else {
				
		 printf("\n\n\n\t\t\t\t\tIslem basariyla gerceklestirilmistir.");
		   ptr->bakiye -= tutar;//bakiyeyi güncelliyoruz
		   fprintf(makbuz,"\n\t\t\t\t\t%.2lf TL para cekilmistir.",tutar);
		}	
}

void parayatirma(struct yeniuye s, struct yeniuye *ptr,FILE* makbuz){
		double tutar;
		printf("\n\n\n\t\t\t\t\tBakiyeniz: %.2lf TL\n",ptr->bakiye);
			printf("\n\n\n\t\t\t\t\tyatiracaginiz tutari giriniz: ");
			scanf("%lf",&tutar);//yatýralacak tutari alýyoruz.
				
		 printf("\n\n\n\t\t\t\t\tIslem basariyla gerceklestirilmistir.");
		ptr->bakiye += tutar;//bakiyeyi güncelliyoruz
		fprintf(makbuz,"\n\t\t\t\t\t%.2lf TL para yatirilmistir.",tutar);
}

void havaleyapma(struct yeniuye s, struct yeniuye *ptr,FILE* makbuz){
		double tutar;
		int isim[50];
		int soyisim[50];
		int  tur;
		unsigned long long int iban;
		printf("\n\n\n\t\t\t\t\tBakiyeniz:%.2lf TL\n\n\n",ptr->bakiye);
			printf("\t\t\t\t\t[1] Kira\n\n\t\t\t\t\t[2] Yatirim\n\n\t\t\t\t\t[3] Egitim \n\n\t\t\t\t\t[4] Aidat \n\n\t\t\t\t\t[5] Diger\n\n\t\t\t\t\tGondereceginiz Havale Turunun Numarasini Tuslayiniz: ");
			scanf("%d",&tur);//switch case iþlemi ile havale türü seçme
			if(tur==1 || tur==3 || tur== 5){
			
			printf("\n\n\t\t\t\t\tHavale yapacaginiz kisinin IBAN numarasini giriniz:   TR ");
			scanf("%llu",&iban);//gönderilecek kiþinin ibanýný alma
			printf("\n\n\t\t\t\t\tHavale yapacaginiz kisinin isim ve soyismi:\n\t\t\t\t\t{ Ornek Isim Girisi: Mehmet KALIN }	");
			scanf("%s %s",isim,soyisim);//havale yapýlacak kiþinin ismi ve soyismi
			printf("\n\n\n\t\t\t\t\tHavale yapacaginiz tutari giriniz: ");
			scanf("%lf",&tutar);// havale tutarý
		}
		else {
			printf("\n\n\n\t\t\t\t\tHavale yapacaginiz tutari giriniz: ");
			scanf("%lf",&tutar);//yatýrým ve aidat için isim sormadan sadece tutar alma iþlemi
		}	
			if (tutar>ptr->bakiye) {//bakiye tutardan küçükse hata ekraný
				printf("\n\n\n\t\t\t\t\tBakiyeniz yetersizdir.Tekrar deneyiniz.");
			
				}
				
			else {
		 printf("\n\n\n\t\t\t\t\tIslem basariyla gerceklestirilmistir.");
		ptr->bakiye -= tutar;//bakiyeden tutarý çýkarma iþlemi
		fprintf(makbuz,"\n\t\t\t\t\t%.2lf TL havale gerceklestirilmistir.",tutar);//havale iþleminin makbuza yazdýrýlmasý
			}					
}

void bakiyesorgulama(struct yeniuye s, struct yeniuye *ptr,FILE* makbuz){
	
	printf("\n\n\t\t\t\t\tTL Bakiyesi: %.2lf TL\n",ptr->bakiye);//TL bakiyesi gösterimi
	printf("\n\n\t\t\t\t\tDOLAR Bakiyesi:  %.2lf Dolar\n",ptr->dolar);//dolar bakiyesi gösterimi
	printf("\n\n\t\t\t\t\tEURO Bakiyesi:  %.2lf Euro\n",ptr->avro);//euro bakiye gösterimi
	printf("\n\n\t\t\t\t\tSTERLIN Bakiyesi:  %.2lf Sterlin\n",ptr->sterlin);//sterlin bakiye gösterimi
	printf("\n\n\t\t\t\t\tYEN Bakiyesi:  %.2lf Japon Yeni\n",ptr->yen);//yen bakiye gösterimi
	printf("\n\n\t\t\t\t\tALTIN Bakiyesi:  %.2lf Gram \n",ptr->graltin);//altýn bakiye gösterimi
}

void faturaodeme(struct yeniuye s, struct yeniuye *ptr,FILE* makbuz){
		
		int faturasecim;
		int telefon;
		int telefonnumara[10];
		double tutar;//burada fonksiyon için gerekli olan parametreleri tanýmladýk...
		int hizmet[10];
		
		printf("\n\n\n\t\t\t\t\tbakiyeniz: %.2lf TL\n\n",ptr->bakiye);
		
				printf("\n\n\n\t\t\t\t\tIslemler\n\n\t\t\t\t\t[1]Telefon faturasi\n\n\t\t\t\t\t[2]Su faturasi\n\n\t\t\t\t\t[3]Elektrik faturasi\n\n\t\t\t\t\t[4]Dogalgaz faturasi\n\n\t\t\t\t\t");
				printf("Hangi faturayi odemek istersiniz ?: ");
				scanf("%d",&faturasecim);// hangi fatura türünü seçmek istediði sorusu
	
					switch(faturasecim) {
			
						case 1 ://telefon faturasý seçilirse...
							printf("\n\n\n\t\t\t\t\tTELEFON FATURASI ODEME");
		
							printf("\n\n\n\t\t\t\t\t[1]Vodafone\n\n\t\t\t\t\t[2]Turkcell\n\n\t\t\t\t\t[3]Turk Telekom");
							printf("\n\n\n\t\t\t\t\tOperatorunuzu seciniz: ");//operatör seçimi
							scanf("%d",&telefon);
							
							printf("\n\n\n\t\t\t\t\tTelefon numaranizi giriniz(basýnda 0 olmadan giriniz!): ");
							scanf("%d",&telefonnumara);//telefon numarasý tuþlanmasý
								printf("\n\n\n\t\t\t\t\tbakiyeniz: %.2lf TL\n\n",ptr->bakiye);
							printf("\n\n\n\t\t\t\t\tFatura ucretini giriniz: ");
							scanf("%lf",&tutar);//fatura ücreti 
								if (tutar >ptr->bakiye) {//bakiye kontrolü
									printf("\n\n\n\t\t\t\t\tYeterli bakiyeniz yoktur.");
									break;
								}
							else {
								
								printf("\n\n\n\t\t\t\t\tIsleminiz basariyla gerceklestirilmistir.");
								ptr->bakiye -= tutar;//Fatura tutarýnýn Bakiyeden Düþme iþlemi
								fprintf(makbuz,"\n\t\t\t\t\t%.2lf TL telefon faturaniz odenmistir.",tutar);
							break ;
							}
			
							case 2 ://su faturasý seçilirse
								printf("\n\n\n\t\t\t\t\tSU FATURASI ODEME");
								printf("\n\n\n\t\t\t\t\t10 haneli hizmet numaranizi hizmet numaranizi giriniz: ");
								scanf("%d",&hizmet);//Ödenilecek fatura için Hizmet numarasý alma
									printf("\n\n\n\t\t\t\t\tbakiyeniz: %.2lf TL\n\n",ptr->bakiye);
								printf("\n\n\n\t\t\t\t\tFatura ucretini giriniz: ");
								scanf("%lf",&tutar);//fatura ücreti 
									if (tutar >ptr->bakiye) {//bakiye kontrolü
										printf("\n\n\n\t\t\t\t\tYeterli bakiyeniz yoktur.");
										break;
									}
								else {
									
									printf("\n\n\n\t\t\t\t\tIsleminiz basariyla gerceklestirilmistir.");
								ptr->bakiye -= tutar;//Fatura tutarýnýn Bakiyeden Düþme iþlemi
								fprintf(makbuz,"\n\t\t\t\t\t%.2lf TL su faturaniz odenmistir.",tutar);
								break ;
								}
		
							case 3 : //Elektrik faturasý seçilirse
								printf("\n\n\n\t\t\t\t\tELEKTRIK FATURASI ODEME");
								printf("\n\n\n\t\t\t\t\t10 haneli hizmet numaranizi hizmet numaranizi giriniz: ");
								scanf("%d",&hizmet);//Ödenilecek fatura için Hizmet numarasý alma
									printf("\n\n\n\t\t\t\t\tbakiyeniz: %.2lf TL\n\n",ptr->bakiye);
								printf("\n\n\n\t\t\t\t\tFatura ucretini giriniz: ");
								scanf("%lf",&tutar);//fatura ücreti 
									if (tutar >ptr->bakiye) {//bakiye kontrolü
										printf("\n\n\n\t\t\t\t\tYeterli bakiyeniz yoktur.");
										break;
									}
									else {									
										printf("\n\n\n\t\t\t\t\tIsleminiz basariyla gerceklestirilmistir.");
										ptr->bakiye -= tutar;//Fatura tutarýnýn Bakiyeden Düþme iþlemi
										fprintf(makbuz,"\n\t\t\t\t\t%.2lf TL elektrik faturaniz odenmistir.",tutar);
										break ;
									}
			
							case 4 : //Doðalgaz faturasý seçilirse
								printf("\n\n\n\t\t\t\t\tDOGALGAZ FATURASI ODEME");
								printf("\n\n\n\t\t\t\t\t10 haneli hizmet numaranizi hizmet numaranizi giriniz: ");
								scanf("%d",&hizmet);//Ödenilecek fatura için Hizmet numarasý alma
								printf("\n\n\n\t\t\t\t\tbakiyeniz: %.2lf TL\n\n",ptr->bakiye);
								printf("\n\n\n\t\t\t\t\tFatura ucretini giriniz: ");
								scanf("%lf",&tutar);//fatura ücreti 
								if (tutar >ptr->bakiye) {//bakiye kontrolü
									printf("\n\n\n\t\t\t\t\tYeterli bakiyeniz yoktur.");
									break;
									}
								else {
								
								printf("\n\n\n\t\t\t\t\tIsleminiz basariyla gerceklestirilmistir.");
								ptr->bakiye -= tutar;//Fatura tutarýnýn Bakiyeden Düþme iþlemi
								fprintf(makbuz,"\n\t\t\t\t\t%.2lf TL dogalgaz faturaniz odenmistir.",tutar);						
								break ;
								}
								}
}

void Doviz(struct yeniuye s,struct yeniuye *ptr,FILE* makbuz){
    double convertedCASE;
	int operator,operator1;
	printf("\t\t\t\t\t[1] Hesaptan Doviz Satin Alma (Doviz Al)\n");
	printf("\t\t\t\t\t[2] Hesaba Doviz Yukleme (Doviz Sat)\n\t\t\t\t\t");
	scanf("%d",&operator1);
	// Döviz alým ve satýmýný iki koþula baðladýk
	if(operator1==1){
		printf("\n\n\n\t\t\t\t\tParanizi cevirmek istediginiz para biriminin numarasini girin\n");
		printf("\n\n\n\t\t\t\t\t[1] DOLAR -> %.2f\n",DOLAR);
		printf("\n\n\n\t\t\t\t\t[2] EURO -> %.2f\n",EURO);
		printf("\n\n\n\t\t\t\t\t[3] STERLIN -> %.2f\n",STERLIN);
		printf("\n\n\n\t\t\t\t\t[4] YEN -> %.3f\n",YEN);
		printf("\n\n\n\t\t\t\t\t[5] GRAM ALTIN -> %.2f\n",GOLD);
	
		scanf("%d",&operator);
		if(operator<1 || operator>5){
			//gerekli deðer aralýðý girilmezse kullnýcýya hata verilecek
			printf("\n\n\n\t\t\t\t\t\aHatali Giris");
			}
		else{
			printf("\n\n\n\t\t\t\t\tNe kadar TL'yi dovize donusturmek istersiniz ?:");
			scanf("%lf",&convertedCASE);
			//çevirilecek paranýn miktarý girildi
			if(convertedCASE > ptr->bakiye || convertedCASE< 0){
				//bakiye yetersizse bu uyarý verilecek
				printf("\n\n\n\t\t\t\t\t\aBakiyeniz Yetersiz Veya Hatali Tuslama Taptiniz");
			}
			else{//bakiye yeterli ise bu koþul saðlanacak
				switch (operator)
				{
				case 1:{
					ptr->bakiye -=convertedCASE;// bakiyeden para çekildi
					printf("\n\n\n\t\t\t\t\tHesabiniz:\n");
					printf("\n\n\n\t\t\t\t\tTL: %.2lf\n",ptr->bakiye);
					ptr->dolar= convertedCASE/DOLAR;//dolar hesabýna eklendi
					printf("\n\n\n\t\t\t\t\tDOLAR: %.2lf\n",ptr->dolar);
					fprintf(makbuz,"\n\t\t\t\t\t%.2lf DOLAR alinmistir.",ptr->dolar);//dolar makbuza eklendi
					}
					break;
				case 2:{
					ptr->bakiye -=convertedCASE;// bakiyeden para çekildi
					printf("\n\n\n\t\t\t\t\tHesabiniz:\n");
					printf("\n\n\n\t\t\t\t\tTL: %.2lf\n",ptr->bakiye);
					ptr->avro= convertedCASE/EURO;
					printf("\n\n\n\t\t\t\t\tEURO: %.2lf\n",ptr->avro);
					fprintf(makbuz,"\n\t\t\t\t\t%.2lf EURO alinmistir.",ptr->avro);//euro makbuza eklendi
					}
					break;
				case 3:{
					ptr->bakiye -=convertedCASE;// bakiyeden para çekildi
					printf("\n\n\n\t\t\t\t\tHesabiniz:\n");
					printf("\n\n\n\t\t\t\t\tTL: %.2lf\n",ptr->bakiye);
					ptr->sterlin= convertedCASE/STERLIN;
					printf("\n\n\n\t\t\t\t\tSTERLIN: %.2lf\n",ptr->sterlin);
					fprintf(makbuz,"\n\t\t\t\t\t%.2lf STERLIN alinmistir.",ptr->sterlin);//sterlin makbuza eklendi
					}
					break;
				case 4:{
					ptr->bakiye -=convertedCASE;// bakiyeden para çekildi
					printf("\n\n\n\t\t\t\t\tHesabiniz:\n");
					printf("\n\n\n\t\t\t\t\tTL: %.2lf\n",ptr->bakiye);
					ptr->yen= convertedCASE/YEN;
					printf("\n\n\n\t\t\t\t\tYEN: %.2lf\n",ptr->yen);
					fprintf(makbuz,"\n\t\t\t\t\t%.2lf YEN alinmistir.",ptr->yen);//yen makbuza eklendi
					}
					break;
				case 5:{
					ptr->bakiye -=convertedCASE;// bakiyeden para çekildi
					printf("\n\n\n\t\t\t\t\tHesabiniz:\n");
					printf("\n\n\n\t\t\t\t\tTL: %.2lf\n",ptr->bakiye);
					ptr->graltin= convertedCASE/GOLD;
					printf("\n\n\n\t\t\t\t\tGRAM ALTIN: %.2lf\n",ptr->graltin);
					fprintf(makbuz,"\n\t\t\t\t\t%.2lf Gram Altin alinmistir.",ptr->graltin);//gram altýn makbuza eklendi
					}
					break;
				
				default:
					break;
				}
			}
		}
	}
	else if(operator1==2){
		printf("\n\n\n\t\t\t\t\tHesabiniza Yuklemek {Satmak} Istediginiz Doviz turu nedir?\n");
		printf("\n\n\n\t\t\t\t\t1) DOLAR -> %.2f\n",DOLAR);
		printf("\n\n\n\t\t\t\t\t2) EURO -> %.2f\n",EURO);
		printf("\n\n\n\t\t\t\t\t3) STERLIN -> %.2f\n",STERLIN);//burada Döviz seçerken Dövizlerin yanlarýnda Kur deðerlerini gösterir
		printf("\n\n\n\t\t\t\t\t4) YEN -> %.3f\n",YEN);
		printf("\n\n\n\t\t\t\t\t5) GRAM ALTIN -> %.2f\n",GOLD);
	
		scanf("%d",&operator);
		if(operator<1 || operator>5){
			printf("\n\n\n\t\t\t\t\t\aHatali Giris");//1 ve 5 arasý haricinde rakam girilirse hata verir
			}
		else{
			printf("\n\n\n\t\t\t\t\tNe kadar dovizi TL ye donusturmek istersiniz ?:\n\t\t\t\t\t");
			printf("(Altinsa gram olarak belirtiniz...)\n\t\t\t\t\t"); 
			scanf("%lf",&convertedCASE);
			//yüklenecek miktar yazýlacak
			if(operator==1 && ptr->dolar<convertedCASE)//hesapta yeterince para varmý kontrolü
                printf("\t\t\t\t\tHesabinizda yeterince Dolar yok");
            else if(operator==2 && ptr->avro<convertedCASE)//hesapta yeterince para varmý kontrolü
                printf("\t\t\t\t\tHesabinizda yeterince Euro yok");
            else if(operator==3 && ptr->sterlin<convertedCASE)//hesapta yeterince para varmý kontrolü
                printf("\t\t\t\t\tHesabinizda yeterince Sterlin yok");
            else if(operator==4 && ptr->yen<convertedCASE)//hesapta yeterince para varmý kontrolü
                printf("\t\t\t\t\tHesabinizda yeterince Yen yok");
            else if(operator==5 && ptr->graltin<convertedCASE)//hesapta yeterince gram altýn varmý kontrolü
                printf("\t\t\t\t\tHesabinizda yeterince Gram Altin yok");
            else{ 
			switch (operator)
				{
				case 1:{
					ptr->bakiye +=convertedCASE*DOLAR;//dolar bakiyeye ekleniyor
					printf("\n\n\n\t\t\t\t\tHesabiniz:\n");
					printf("\n\n\n\t\t\t\t\tTL: %.2lf\n",ptr->bakiye);
					ptr->dolar -= convertedCASE;//dolardan çevrilen miktar çýkarýlacak
					printf("\n\n\n\t\t\t\t\tDOLAR: %.2lf ",ptr->dolar);
					fprintf(makbuz,"\n\t\t\t\t\t DOLAR: %.2lf ",ptr->dolar);
					}
					break;
				case 2:{
					ptr->bakiye +=convertedCASE*EURO;//euro bakiyeye ekleniyor
					printf("\n\n\n\t\t\t\t\tHesabiniz:\n");
					printf("\n\n\n\t\t\t\t\tTL: %.2lf\n",ptr->bakiye);
					ptr->avro -= convertedCASE;//eurodan çevrilen miktar çýkarýlacak
					printf("\n\n\n\t\t\t\t\t EURO: %.2lf \n",ptr->avro);
					fprintf(makbuz,"\n\t\t\t\t\tEURO: %.2lf",ptr->avro);
					}
					break;
				case 3:{
					ptr->bakiye +=convertedCASE*STERLIN;//sterlin bakiyeye ekleniyor
					printf("\n\n\n\t\t\t\t\tHesabiniz:\n");
					printf("\n\n\n\t\t\t\t\tTL: %.2lf\n",ptr->bakiye);
					ptr->sterlin -= convertedCASE;//sterlindan çevrilen miktar çýkarýlacak
					printf("\n\n\n\t\t\t\t\tSTERLIN: %.2lf \n",ptr->sterlin);
					fprintf(makbuz,"\n\t\t\t\t\tSTERLIN: %.2lf",ptr->sterlin);
					}
					break;
				case 4:{
					ptr->bakiye +=convertedCASE*YEN;//yen bakiyeye ekleniyor
					printf("\n\n\n\t\t\t\t\tHesabiniz:\n");
					printf("\n\n\n\t\t\t\t\tTL: %.2lf\n",ptr->bakiye);
					ptr->yen -= convertedCASE;//yendan çevrilen miktar çýkarýlacak
					printf("\n\n\n\t\t\t\t\tYEN: %.2lf\n",ptr->yen);
					fprintf(makbuz,"\n\t\t\t\t\tYEN: %.2lf",ptr->yen);
					}
					break;
				case 5:{
					ptr->bakiye +=convertedCASE*GOLD;//gold bakiyeye ekleniyor
					printf("\n\n\n\t\t\t\t\tHesabiniz:\n");
					printf("\n\n\n\t\t\t\t\tTL: %.2lf\n",ptr->bakiye);
					ptr->graltin -= convertedCASE;//golddan çevrilen miktar çýkarýlacak
					printf("\n\n\n\t\t\t\t\tGRAM ALTIN: %.2lf\n",ptr->graltin);
					fprintf(makbuz,"\n\t\t\t\t\tGRAM ALTIN: %.2lf",ptr->graltin);
					}
					break;
					default:
					break;
				}
			}
		}
	}
}

void KrediTalep(struct yeniuye s, struct yeniuye *ptr,FILE* makbuz){
	int yas,islem2;
	double geciktirme,pesinat,kreditutari;//kredi için kullanýlacak olan tanýmlamalar
	char onceden[0],besbintl[0];
	char H,h,E,e;//evet hayýr harfleri
	printf("\n\t\t\t\t\tKredi Islemlerine Hosgeldiniz... \n\n");
	printf("\t\t\t\t\tLutfen Yasinizi Giriniz:    ");
	scanf("%d",&yas);
	if(yas < 25){// yaþ kontrolü ...
	printf("\n\n\t\t\t\aBankamiz 7-24 Yas Araligindaki Musterilerimize Kredi Verememektedir!!! Iyi Gunler Dileriz...\n\n");
	}
	else if(yas >= 25){//yaþ 25 den büyükse sistem çalýþýr...

	printf("\t\t\t\t\tDaha once bir kredi aldiniz mi?\t{E veya H seklinde giriniz}:    ");
	scanf("%s",&onceden[0]);//önceki dönem kredisi için evet hayýr sorgusu
	if(onceden[0] == 'H' || onceden[0] == 'h'){// Hayýr için harfler
		printf("\n\n\t\t\t\t\tDaha onceden bir kredi almadiginiz icin kredi notunuz olusturulmamýstýr..\n Bu sebeple bankamiz size ihtiyac kredisi altinda sadece 5000 tl kredi verebilecektir...\n\n");
		printf("\t\t\t\t\t5000 tl krediyi almak ister misiniz?\t{E veya H seklinde giriniz}\t{5000 tl den daha az kredi tutari verilmemektedir...}\n\n");
		scanf("%s",&besbintl[0]);
		if(besbintl[0] == 'E' || besbintl[0] == 'e'){//Evet için harfler
			ptr->bakiye = ptr->bakiye + 5000;
			printf("\t\t\t\t\t5000 TL Krediniz TL Hesabiniza Aktarilmistir Gule Gule Kullaniniz...\n\n");
			fprintf(makbuz,"\n\t\t\t\t\t5000 TL kredi cekilmistir.");//iþlemin bakbuza yazdýrýlmasý
		}
		else{
			printf("\t\t\t\t\tKredi almadiniz....\n\n");//denemelik 5000 tl krediyi istemeyen kullanýcý anamenüye yönlendirilir...
		}
		
	}
	if(onceden[0] == 'E' || onceden[0] == 'e'){//Evet için harfler
		
	printf("\t\t\t\t\tKredi Turleri\n\n\t\t\t\t\t[1]Ihtiyac Kredisi\n\n\t\t\t\t\t[2]Arac Kredisi\n\n\t\t\t\t\t[3]Ev Kredisi\n\n");//kredi ana menüsü
	
	printf("\t\t\t\t\tLutfen sececeginiz kredi turunun rakamini giriniz:\t");
	scanf("%d",&islem2);
	switch(islem2) {//kredi türü seçme iþlemi
	case 1 :	
		
		printf("\t\t\t\t\tDaha onceden aldiniz kredinin odeme tarihini kac gun geciktirdiniz? \n\t\t\t\t\t{Geciktirmediyseniz 0 tuslayiniz}: ");
		scanf("%lf",&geciktirme);//kredi notu kontrolu
		if(geciktirme < 1){//kredi notu yüksek olanlar için
			printf("\t\t\t\t\tKredi notunuz <10> baz  \n\n");
			printf("\t\t\t\t\tIhtiyac kredisi icin size verebilecegimiz en fazla kredi tutari 50.000 tl dir\n\n");
			printf("\t\t\t\t\tLutfen Pesinat miktarinizi giriniz.\n\t\t\t\t\t{IHTIYAC KREDILERINDE 30.000 tl altindaki pesinatlar kabul edilmeyecektir...}: ");
			scanf("%lf",&pesinat);
			if(pesinat < 30000){//peþinat kontrolu az ise kredi verilmez
				printf("\n\n\t\t\t\t\tPesinat Miktarini karsilayamadiniz...\n\n");
				break;
			}
			else{
				printf("\t\t\t\t\tNe kadar kredi istiyorsunuz:     ");
				scanf("%lf",&kreditutari);
				if(kreditutari < 50001){//kredi tutar kontrolü
					ptr->bakiye = ptr->bakiye + kreditutari;
			printf("\n\n\t\t\t\t\t%.2lf TL krediniz Hesabiniza aninda aktarilmistir Gule Gule Kullaniniz...\n\n",kreditutari);
			fprintf(makbuz,"\n\t\t\t\t\t%.2lf TL ihtiyac kredisi cekilmistir.",kreditutari);//iþlemin bakbuza yazdýrýlmasý
								break;
				}
				else {//Kredi limit kontrolu fazla ise kredi verilmez
					printf("\t\t\t\t\tEn fazla Verebilecegimiz Limitten fazlasini istediginiz icin Size kredi veremedik...\n\n");
					break;
					}	
				}	
			}
		if(geciktirme >= 1){//kredi notu düþükler için
			printf("\t\t\t\t\tKredi notunuz <5> \n\n");
			printf("\t\t\t\t\tIhtiyac kredisi icin size verebilecegimiz en fazla kredi tutari 30.000 tl dir\n\n");
			printf("\t\t\t\t\tLutfen Pesinat miktarinizi giriniz.\n\t\t\t\t\t{IHTIYAC KREDILERINDE 30.000 tl altindaki pesinatlar kabul edilmeyecektir...}: ");
			scanf("%lf",&pesinat);
			if(pesinat < 30000){//peþinat kontrolu az ise kredi verilmez
				printf("\n\n\t\t\t\t\tPesinat Miktarini karsilayamadiniz...\n\n");
				break;
			}
			else{
				printf("\t\t\t\t\tNe kadar kredi istiyorsunuz:     ");
				scanf("%lf",&kreditutari);
				if(kreditutari < 30001){//kredi tutar kontrolü
					ptr->bakiye = ptr->bakiye + kreditutari;
			printf("\n\n\t\t\t\t\t%.2lf TL krediniz Hesabiniza aninda aktarilmistir Gule Gule Kullaniniz...\n\n",kreditutari);
			fprintf(makbuz,"\n\t\t\t\t\t%.2lf TL ihtiyac kredisi cekilmistir.",kreditutari);	//iþlemin bakbuza yazdýrýlmasý
				break;
				}
											
				else {//Kredi limit kontrolu fazla ise kredi verilmez
					printf("\t\t\t\t\tEn fazla Verebilecegimiz Limitten fazlasini istediginiz icin Size kredi veremedik...\n\n");
					break;
				}
			}
		}					
		
		case 2 :	
		
		printf("\n\t\t\t\t\tDaha onceden aldiniz kredinin odeme tarihini kac gun geciktirdiniz?\n\t\t\t\t\t{Geciktirmediyseniz 0 tuslayiniz}: ");
		scanf("%lf",&geciktirme);
		if(geciktirme < 1){//kredi notu yüksek olanlar için
			printf("\t\t\t\t\tKredi notunuz <10> \n\n");
			printf("\t\t\t\t\tARAC KREDISI icin size verebilecegimiz en fazla kredi tutari 100.0000 tl dir\n\n");
			printf("\t\t\t\t\tLutfen Pesinat miktarinizi giriniz.\n\t\t\t\t\t{ARAC KREDILERINDE 30.000 tl altindaki pesinatlar kabul edilmeyecektir...}: ");
			scanf("%lf",&pesinat);
			if(pesinat < 30000){//peþinat kontrolu az ise kredi verilmez
				printf("\n\n\t\t\t\t\tPesinat Miktarini karsilayamadiniz...\n\n");
				
				break;
			}
			else{
				printf("\t\t\t\t\tNe kadar kredi istiyorsunuz:     ");
				scanf("%lf",&kreditutari);
				if(kreditutari < 100001){//kredi tutar kontrolü
					ptr->bakiye = ptr->bakiye + kreditutari;
			printf("\n\n\t\t\t\t\t%.2lf TL krediniz Hesabiniza aninda aktarilmistir Gule Gule Kullaniniz...\n\n",kreditutari);
			fprintf(makbuz,"\n\t\t\t\t\t%.2lf TL arac kredisi cekilmistir.",kreditutari);		//iþlemin bakbuza yazdýrýlmasý
					break;
				}
				else {//Kredi limit kontrolu fazla ise kredi verilmez
					printf("\t\t\t\t\tEn fazla Verebilecegimiz Limitten fazlasini istediginiz icin Size kredi veremedik...\n\n");
					break;
				}	}	}
		if(geciktirme >= 1){//kredi notu düþükler için
			printf("\t\t\t\t\tKredi notunuz <5> \n\n");
			printf("\t\t\t\t\tARAC KREDISI icin size verebilecegimiz en fazla kredi tutari 70.000 tl dir\n\n");
			printf("\t\t\t\t\tLutfen Pesinat miktarinizi giriniz.\n\t\t\t\t\t{ARAC KREDILERINDE 30.000 tl altindaki pesinatlar kabul edilmeyecektir...}: ");
			scanf("%lf",&pesinat);
			if(pesinat < 30000){//peþinat kontrolu az ise kredi verilmez
				printf("\n\n\t\t\t\t\tPesinat Miktarini karsilayamadiniz...\n\n");
				break;
			}
			else{
				printf("\t\t\t\t\tNe kadar kredi istiyorsunuz:     ");
				scanf("%lf",&kreditutari);
				if(kreditutari < 70001){//kredi tutar kontrolü
					ptr->bakiye = ptr->bakiye + kreditutari;
			printf("\n\n\t\t\t\t\t%.2lf TL krediniz Hesabiniza aninda aktarilmistir Gule Gule Kullaniniz...\n\n",kreditutari);
			fprintf(makbuz,"\n\t\t\t\t\t%.2lf TL arac kredisi cekilmistir.",kreditutari);//iþlemin bakbuza yazdýrýlmasý	
				break;
				}
							
				else {//Kredi limit kontrolu fazla ise kredi verilmez
					printf("\t\t\t\t\tEn fazla Verebilecegimiz Limitten fazlasini istediginiz icin Size kredi veremedik...\n\n");
					break;
				}
			}	
		}
		
		case 3 :	
		
		printf("\t\t\t\t\tDaha onceden aldiniz kredinin odeme tarihini kac gun geciktirdiniz? \n\t\t\t\t\t{Geciktirmediyseniz 0 tuslayiniz}: ");
		scanf("%lf",&geciktirme);
		if(geciktirme < 1){//kredi notu yüksek olanlar için
			printf("\n\n\t\t\t\t\tKredi notunuz <10> \n\n");
			printf("\t\t\t\t\tEV KREDISI icin size verebilecegimiz en fazla kredi tutari 250.000 tl dir\n\n");
			printf("\t\t\t\t\tLutfen Pesinat miktarinizi giriniz.\n\t\t\t\t\t{EV KREDILERINDE 150.000 tl altindaki pesinatlar kabul edilmeyecektir...}: ");
			scanf("%lf",&pesinat);
			if(pesinat < 150000){//peþinat kontrolu az ise kredi verilmez
				printf("\n\n\t\t\t\t\tPesinat Miktarini karsilayamadiniz...\n\n");
				break;
			}
			else{
				printf("\t\t\t\t\tNe kadar kredi istiyorsunuz:     ");
				scanf("%lf",&kreditutari);
				if(kreditutari < 250001){//kredi tutar kontrolü
					ptr->bakiye = ptr->bakiye + kreditutari;
			printf("\n\n\t\t\t\t\t%.2lf TL krediniz Hesabiniza aninda aktarilmistir Gule Gule Kullaniniz...\n\n",kreditutari);
			fprintf(makbuz,"\n\t\t\t\t\t%.2lf TL ev kredisi cekilmistir.",kreditutari);	//iþlemin bakbuza yazdýrýlmasý
				break;
				}				

				else {//Kredi limit kontrolu fazla ise kredi verilmez
					printf("\t\t\t\t\tEn fazla Verebilecegimiz Limitten fazlasini istediginiz icin Size kredi veremedik...\n\n");
					break;
				}	}	}
		if(geciktirme >= 1){//kredi notu düþükler için
			printf("\t\t\t\t\tKredi notunuz <5> \n\n");
			printf("\t\t\t\t\tEV KREDISI icin size verebilecegimiz en fazla kredi tutari 200.000 tl dir\n\n");
			printf("\t\t\t\t\tLutfen Pesinat miktarinizi giriniz.\n\t\t\t\t\t{EV KREDILERINDE 150.000 tl altindaki pesinatlar kabul edilmeyecektir...}: ");
			scanf("%lf",&pesinat);
			if(pesinat < 150000){//peþinat kontrolu az ise kredi verilmez
				printf("\n\n\t\t\t\t\tPesinat Miktarini karsilayamadiniz...\n\n");
				break;
			}
			else{
				printf("\t\t\t\t\tNe kadar kredi istiyorsunuz:     ");
				scanf("%lf",&kreditutari);
				if(kreditutari < 200.001){//kredi tutar kontrolü
					ptr->bakiye = ptr->bakiye + kreditutari;
			printf("\n\n\t\t\t\t\t%.2lf TL krediniz Hesabiniza aninda aktarilmistir Gule Gule Kullaniniz...\n\n",kreditutari);
			fprintf(makbuz,"\n\t\t\t\t\t%.2lf TL ev kredisi cekilmistir.",kreditutari);	//iþlemin bakbuza yazdýrýlmasý
					break;
				}	

				else {//Kredi limit kontrolu fazla ise kredi verilmez
					printf("\t\t\t\t\tEn fazla Verebilecegimiz Limitten fazlasini istediginiz icin Size kredi veremedik...\n\n");
					break;
						}
					}
				}
			}
		}
	}
}

void makbuzYazdir(FILE* makbuz,struct yeniuye s, struct yeniuye *ptr) {
	printf("\n\t\t\t\t\tMAKBUZ");
	while(!feof(makbuz)){
		printf("%c",fgetc((makbuz)));
		
	}
printf("\n\t\t\t\t\tson bakiye: %.2lf TL",ptr->bakiye);
}



