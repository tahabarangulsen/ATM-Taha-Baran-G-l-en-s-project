#ifndef ATMLibrary
#define ATMLibrary
#include <stdio.h>
#include <stdlib.h>
#define DOLAR 7.42
#define EURO 9.06
#define STERLIN 10.15
#define YEN 7.20
#define GOLD 452.98
FILE *makbuz;
struct yeniuye{
	unsigned long long int TcNo;
	double bakiye;
	int sifre;
	double dolar;
	double avro;
	double sterlin;
	double yen;
	double graltin;
};
void Yeniuyelik(struct yeniuye s, struct yeniuye *ptr);
void SifreGirisi(struct yeniuye s, struct yeniuye *ptr);
void paracekme(struct yeniuye s, struct yeniuye *ptr,FILE* makbuz);
void parayatirma(struct yeniuye s, struct yeniuye *ptr,FILE* makbuz);
void havaleyapma(struct yeniuye s, struct yeniuye *ptr,FILE* makbuz);
void bakiyesorgulama(struct yeniuye s, struct yeniuye *ptr,FILE* makbuz);
void faturaodeme(struct yeniuye s, struct yeniuye *ptr,FILE* makbuz);
void KrediTalep(struct yeniuye s, struct yeniuye *ptr,FILE* makbuz);
void Doviz(struct yeniuye s,struct yeniuye *ptr,FILE* makbuz);


void makbuzYazdir(FILE* makbuz,struct yeniuye s, struct yeniuye *ptr);

#endif

