#include<ctime>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<assert.h>
#include<random>
#include<algorithm>
 #include<numeric>
#include<math.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include"main.h"
#include<stdio.h>
#include<string>
#include<cmath>
using namespace std;const int phjx= 14;bool coEcs(); bool Rnest();void gZRf
();SDL_Texture*aeoO(std::string path);SDL_Window*w50fr=NULL;SDL_Renderer
*ofJi=NULL;namespace Ubqt{class qawV{std::vector<int>bmy7;public: qawV (
);qawV(unsigned int TjN9);double S2qp(double VTo9JD,double jQ2Fj_, double
 o4jTCa9r) ;private :double rx8b(double akdh);double LrZXP(double akdh ,
double MSuLw, double mJBTEJ); double dkf6(int Vbkg,double VTo9JD,double
 jQ2Fj_ ,double o4jTCa9r);};qawV::qawV(){bmy7= {151,160,137, 91 ,90,15,
131,13,201,95, 96 ,53,194 ,233,7, 225,140,36,103,30, 69, 142, 8,99,37, 240
,21,10,23,190,6,148,247,120,234 ,75,0,26,197, 62,94 ,252,219,203,117,35
,11, 32,57,177,33,88 ,237,149,56,87, 174,20,125,136,171,168,68,175, 74,
 165,71,134,139,48,27,166,77,146, 158,231,83,111,229,122,60,211,133 ,230
,220 ,105 ,92,41 , 55,46,245,40,244,102, 143,54,65,25,63,161 ,1,216,80,
 73, 209 ,76 ,132,187,208,89,18,169,200 ,196,135 , 130,116,188,159,86,164
,100,109,198 , 173, 186,3,64,52,217 ,226,250, 124,123,5, 202,38,147,118
,126,255,82, 85,212,207,206,59,227 ,47,16 ,58,17,182,189,28, 42 ,223,183
 ,170,213, 119,248 ,152, 2, 44,154 ,163,70 ,221 ,153 ,101,155 ,167,43,172
,9,129,22 ,39 ,253,19,98,108,110,79 ,113, 224,232,178,185, 112 , 104,218
,246,97,228,251,34,242,193,238,210,144, 12,191,179 ,162,241, 81,51,145,
 235,249,14 ,239,107,49,192,214, 31,181 ,199,106 ,157,184,84,204,176,115
,121,50,45,127 ,4 ,150,254,138, 236, 205,93,222,114 ,67 ,29,24,72,243 ,
141 ,128, 195, 78,66 ,215,61,156,180};bmy7.insert(bmy7 .end() ,bmy7.begin
( ),bmy7.end());}qawV::qawV(unsigned int TjN9) {bmy7.resize(256); std::
iota(bmy7.begin(),bmy7. end( ),0 ); std::default_random_engine BEeSH(TjN9
);std::shuffle( bmy7.begin(),bmy7.end () ,BEeSH);bmy7.insert(bmy7.end()
,bmy7.begin( ),bmy7 .end() );}double qawV :: S2qp(double VTo9JD, double
 jQ2Fj_,double o4jTCa9r){int D1PU=(int )floor(VTo9JD)&255 ; int LEHZX=(
int)floor( jQ2Fj_)& 255;int HMG7H=(int)floor(o4jTCa9r)&255; VTo9JD-=floor
(VTo9JD) ;jQ2Fj_-=floor(jQ2Fj_);o4jTCa9r-=floor (o4jTCa9r);double bizY =
rx8b(VTo9JD);double TThja= rx8b(jQ2Fj_ );double dP0c = rx8b(o4jTCa9r );
int Pv5NG=bmy7[D1PU ]+LEHZX;int M2eYFW=bmy7[Pv5NG]+HMG7H;int SuK8=bmy7 [
Pv5NG+1 ]+HMG7H; int cdj4=bmy7[D1PU+1]+LEHZX;int yyo8hhK=bmy7[cdj4]+ HMG7H
;int UL3vp=bmy7[cdj4 +1] + HMG7H; double vAJu=LrZXP(dP0c,LrZXP(TThja ,LrZXP
 (bizY, dkf6( bmy7[M2eYFW],VTo9JD,jQ2Fj_,o4jTCa9r) ,dkf6(bmy7[ yyo8hhK]
,VTo9JD- 1,jQ2Fj_ ,o4jTCa9r)),LrZXP(bizY,dkf6( bmy7 [ SuK8],VTo9JD , jQ2Fj_
-1,o4jTCa9r) , dkf6( bmy7 [UL3vp],VTo9JD-1 ,jQ2Fj_ -1 ,o4jTCa9r ))),LrZXP
(TThja,LrZXP(bizY,dkf6(bmy7[M2eYFW+1],VTo9JD,jQ2Fj_,o4jTCa9r-1), dkf6(bmy7
[yyo8hhK+ 1],VTo9JD- 1, jQ2Fj_,o4jTCa9r-1)),LrZXP(bizY,dkf6( bmy7 [ SuK8
+ 1] ,VTo9JD,jQ2Fj_ -1,o4jTCa9r-1),dkf6(bmy7[UL3vp+1 ],VTo9JD -1,jQ2Fj_
- 1,o4jTCa9r-1))));return(vAJu+1.0)/ 2.0;}double qawV::rx8b(double akdh
){ return akdh*akdh* akdh*(akdh*(akdh*6- 15)+10 );} double qawV::LrZXP(
double akdh, double MSuLw,double mJBTEJ){return MSuLw+akdh* (mJBTEJ-MSuLw
);}double qawV::dkf6(int Vbkg,double VTo9JD,double jQ2Fj_, double o4jTCa9r
){int SHSpK9w=Vbkg&15;double bizY=SHSpK9w<8?VTo9JD:jQ2Fj_,TThja= SHSpK9w
 <4?jQ2Fj_ :SHSpK9w==12|| SHSpK9w==14? VTo9JD :o4jTCa9r;return((SHSpK9w
&1)== 0? bizY:-bizY)+(( SHSpK9w&2) == 0?TThja:-TThja);}}namespace QjpC{
class AswF3{public:float fh2q,BYPT,aJQtT , pTB9V;AswF3():fh2q (),BYPT( )
,aJQtT(), pTB9V() {}AswF3(float Vy4mp,float PrWd7pf ,float tJb8W,float Fp6N
): fh2q( Vy4mp) ,BYPT(tJb8W),aJQtT (PrWd7pf),pTB9V(Fp6N){if (pTB9V<aJQtT
){std::swap (fh2q, BYPT);std:: swap(aJQtT,pTB9V);}}}; void iVfy(const AswF3
 & phmCnR,const AswF3 &oMCk){float VNOL=(float)( phmCnR.pTB9V -phmCnR.aJQtT
);if(VNOL== 0.0f)return;float xFaO= (float)(oMCk.pTB9V-oMCk.aJQtT);if(xFaO
==0.0f)return;float v_8sx=phmCnR.BYPT-phmCnR.fh2q;float F2Uz4=oMCk .BYPT
-oMCk .fh2q;float nR_R=(oMCk.aJQtT-phmCnR .aJQtT)/VNOL;float flO6KTU=1.0f
/ VNOL; float US4SEB=0.0f ;float k3YE=1.0f/ xFaO;for(int jQ2Fj_= oMCk.aJQtT
;jQ2Fj_<oMCk.pTB9V; jQ2Fj_++){SDL_RenderDrawLine(ofJi,phmCnR.fh2q+v_8sx
*nR_R,jQ2Fj_,oMCk .fh2q +F2Uz4 *US4SEB ,jQ2Fj_);nR_R+=flO6KTU ;US4SEB+=
k3YE ;}} void cBTZU (int fh2q,int aJQtT,int BYPT,int pTB9V ,int iXnV,int
 Nf51){ AswF3 Pwde[3 ];Pwde[0]=AswF3(fh2q ,aJQtT,BYPT,pTB9V ) ; Pwde[ 1
]= AswF3(BYPT ,pTB9V,iXnV ,Nf51);Pwde[2 ]=AswF3(iXnV ,Nf51,fh2q, aJQtT)
;int MM3RfASyZ=0; int CJ9Q=0 ;for (int S9cm1=0;S9cm1 <3;S9cm1++) {int length
=Pwde[S9cm1 ].pTB9V-Pwde[ S9cm1].aJQtT;if(length>MM3RfASyZ){MM3RfASyZ=length
;CJ9Q=S9cm1;}}int Ipp0cKAU =(CJ9Q+ 1) %3;int EUuS=(CJ9Q +2)%3;iVfy(Pwde
[CJ9Q],Pwde[Ipp0cKAU ]);iVfy(Pwde[CJ9Q],Pwde[EUuS ]);}}int B73S(int max
){int b18T=rand ()%max ;if(b18T < 0){b18T*=-1 ;}return b18T;}class d55aA
 { public : float VTo9JD, jQ2Fj_;d55aA():VTo9JD(),jQ2Fj_(){}d55aA(float
 chPFr, float gHwt): VTo9JD(chPFr),jQ2Fj_(gHwt) { } };vector<d55aA>eJnTG6koC
,WceZ;d55aA&jmXmtHT (vector<d55aA>&bmy7,int VTo9JD,int jQ2Fj_){return bmy7
[jQ2Fj_ *muE_+ VTo9JD];}string vuuH(int VTo9JD ){if( VTo9JD==0) {return
"0"; }string b18T ="";int oRof;while( VTo9JD){oRof= VTo9JD% 10;VTo9JD=(
VTo9JD-oRof)/10;b18T.insert(b18T . begin(),'0'+oRof);}return b18T;}float
 nhhB_65( float fh2q, float aJQtT,float BYPT,float pTB9V){float VTo9JD =
BYPT-fh2q;float jQ2Fj_=pTB9V-aJQtT; return sqrt( VTo9JD*VTo9JD+ jQ2Fj_*
 jQ2Fj_);}void GATb(int vIeM ){string ojFXGJWrq3="out/"+vuuH(vIeM)+ ".bmp"
 ;SDL_Surface *wwnlDC=SDL_CreateRGBSurface(0,nLaD8Go,cSLu,32, 0x00ff0000
, 0x0000ff00,0x000000ff, 0xff000000);SDL_RenderReadPixels(ofJi,NULL,SDL_PIXELFORMAT_ARGB8888
,wwnlDC->pixels,wwnlDC->pitch) ;SDL_SaveBMP(wwnlDC,ojFXGJWrq3 .c_str())
; SDL_FreeSurface(wwnlDC); }void sKaJ (vector <d55aA> &bmy7){ bmy7. resize
 (muE_*eexsl, d55aA(0,0) );} void yRx_3(vector< d55aA>&bmy7,char ZIpGe)
{for(int VTo9JD=muE_- 1;VTo9JD>= 0; VTo9JD--){for (int jQ2Fj_ =eexsl-1 ;
jQ2Fj_>=0;jQ2Fj_--){ d55aA&IWAa=jmXmtHT( bmy7,VTo9JD,jQ2Fj_);SDL_SetRenderDrawColor
 (ofJi,ZIpGe, IWAa.VTo9JD< 0? 0x80:0x00,IWAa.jQ2Fj_<0?0x80:0x00, 0xFF);
SDL_RenderDrawLine(ofJi,VTo9JD*MX9YlYatB, jQ2Fj_*MX9YlYatB,VTo9JD*MX9YlYatB
+IWAa. VTo9JD,jQ2Fj_*MX9YlYatB+ IWAa.jQ2Fj_ ); }}}int wIL7iUykY;float zX6G
;void ut3uD4I (float VTo9JD,float jQ2Fj_,int XirxtmU, int N4Zb,int WWUr
,float ojFXGJWrq3,float BG5T_Be,bool AYF3){int TpLlC ,jRuzm,lJoM ;int lssGK
=B73S(0x79)+XirxtmU;int oSlE2O = B73S(0x79 )+N4Zb ;int nTZuk=B73S(0x79)
+WWUr;float chPFr =VTo9JD* MX9YlYatB ;float gHwt=jQ2Fj_*MX9YlYatB;float
 AKhi=(jmXmtHT(eJnTG6koC,VTo9JD, jQ2Fj_).VTo9JD+10)*ojFXGJWrq3;if( AYF3
){wIL7iUykY=10;zX6G=float(B73S(100))/100; } float fus3,Tj6i,rE5o,Ve4N,WgT2
,UP96i;int mP_c=5; if(BG5T_Be>=0){if( AKhi > BG5T_Be){AKhi=BG5T_Be;}else
 if(-AKhi>BG5T_Be) {AKhi=-BG5T_Be; }fus3=0;Tj6i=0 ;rE5o=0;Ve4N=0 ;WgT2=
0;UP96i=AKhi;mP_c=1;} else{fus3=float(B73S(200)-100)/ 100*AKhi/8 ;Tj6i=
float (B73S(200)-100)/100*AKhi/6; rE5o=float(B73S( 200)-100)/100*AKhi/4
 ;Ve4N=float(B73S(200)-100)/100*AKhi/3;WgT2=float(B73S(200)- 100)/100* AKhi
 /2;UP96i=AKhi ;}float TWKN= M_PI/wIL7iUykY*2;bool M4DywQ=false;for(int
 S9cm1= wIL7iUykY;S9cm1;S9cm1 --){TpLlC=std::min(lssGK+B73S(0x19),255 )
;jRuzm= std:: min(oSlE2O+B73S ( 0x19) , 255);lJoM=std::min(nTZuk + B73S
(0x19),255);SDL_SetRenderDrawColor(ofJi,TpLlC, jRuzm,lJoM,0xFF );for(int
 vIeM= mP_c;vIeM;vIeM--){float QwAv=(float(vIeM +(M4DywQ? -1:0))/mP_c* 2
-1)*( M4DywQ?1: - 1);float NYBmfq =(float( vIeM +(M4DywQ? 0:1))/ mP_c *
2-1)*(M4DywQ ?1:-1); float tHd_=fus3*pow (QwAv, 5) +Tj6i* pow(QwAv,4)+rE5o
*pow(QwAv, 3) +Ve4N *pow(QwAv,2)+WgT2 *QwAv+UP96i ; float d1RdtV=fus3*pow
(NYBmfq,5)+Tj6i*pow(NYBmfq,4)+rE5o*pow(NYBmfq,3)+Ve4N*pow(NYBmfq, 2 ) +
WgT2 *NYBmfq+UP96i;float Ul8W =TWKN*(float(S9cm1)+float(vIeM )/mP_c)+zX6G
; float GFLY=TWKN*(float(S9cm1 )+float(vIeM +1)/mP_c)+zX6G; float YN1P4
=chPFr+tHd_* cos(Ul8W );float X_Ir=gHwt+tHd_*sin(Ul8W) ;float IIDSdTv=chPFr
 +d1RdtV*cos(GFLY) ;float iFYM=gHwt +d1RdtV*sin(GFLY);QjpC:: cBTZU(chPFr
,gHwt ,YN1P4, X_Ir,IIDSdTv,iFYM);}M4DywQ=!M4DywQ ;}}std::vector<d55aA>qWyVk
;void scTR(float VTo9JD,float jQ2Fj_,int max){float BYPT,pTB9V,n3Kyd;float
 aAX0w=0;char mJBTEJ=B73S(0xFF);const float q1yR=1;for(int S9cm1=max; S9cm1
;S9cm1-- ){n3Kyd =float (S9cm1 )/float( max)/10; BYPT=VTo9JD+jmXmtHT( WceZ
,VTo9JD,jQ2Fj_).VTo9JD*n3Kyd; pTB9V=jQ2Fj_+jmXmtHT(WceZ,VTo9JD,jQ2Fj_).
 jQ2Fj_* n3Kyd; aAX0w+= nhhB_65(VTo9JD,jQ2Fj_,BYPT, pTB9V);if( aAX0w>=q1yR
) {aAX0w-=q1yR;if(B73S( 30)==0){ qWyVk.push_back(d55aA(VTo9JD,jQ2Fj_ ) )
 ;} else{ ut3uD4I(VTo9JD,jQ2Fj_, 0x40,0xC0,0x00,-0.5,3 , true);}} SDL_SetRenderDrawColor
(ofJi,0x00 ,mJBTEJ,0x00, 0xFF);VTo9JD=BYPT;jQ2Fj_=pTB9V ;if(VTo9JD<0 ||
VTo9JD>=muE_||jQ2Fj_ <0||jQ2Fj_ >=eexsl){break;}} } void oWIK6(int fh2q
, int aJQtT,int BYPT,int pTB9V,d55aA SHSpK9w){ for(int VTo9JD=fh2q; VTo9JD
< BYPT ;VTo9JD++) { for (int jQ2Fj_= aJQtT;jQ2Fj_<pTB9V;jQ2Fj_++){jmXmtHT
( eJnTG6koC ,VTo9JD,jQ2Fj_)=SHSpK9w;} }}bool coEcs(){bool Axe8pou=true;
 if(SDL_Init(SDL_INIT_VIDEO) <0){printf("SDL Error: %s\n",SDL_GetError(
));Axe8pou=false;}else{w50fr=SDL_CreateWindow("Značky LOL",SDL_WINDOWPOS_UNDEFINED
,SDL_WINDOWPOS_UNDEFINED,nLaD8Go,cSLu,SDL_WINDOW_SHOWN);if(w50fr ==NULL
){printf("SDL Error: %s\n",SDL_GetError () ); Axe8pou= false;}else{ofJi
 = SDL_CreateRenderer (w50fr ,- 1, SDL_RENDERER_ACCELERATED);if(ofJi==NULL
){printf("SDL Error: %s\n",SDL_GetError());Axe8pou=false ; }else{SDL_SetRenderDrawColor
( ofJi,0xFF,0xFF,0xFF,0xFF);int WnXAc=IMG_INIT_PNG; if( !(IMG_Init(WnXAc
 )&WnXAc ) ){printf("SDL_image Error: %s\n",IMG_GetError());Axe8pou =false
;} }}}return Axe8pou;}bool Rnest (){bool Axe8pou=true; return Axe8pou;}
 void gZRf (){SDL_DestroyRenderer(ofJi);SDL_DestroyWindow(w50fr);w50fr=
NULL;ofJi= NULL; IMG_Quit() ;SDL_Quit ();}SDL_Texture*aeoO(std::string path
) {SDL_Texture*j9Nx9=NULL;SDL_Surface* fOcgkfg=IMG_Load(path.c_str());if
(fOcgkfg==NULL){printf("Unable to load image %s! SDL_image Error: %s\n"
, path.c_str(),IMG_GetError());}else{j9Nx9=SDL_CreateTextureFromSurface
(ofJi,fOcgkfg);if(j9Nx9==NULL){printf("Unable to create texture from %s! SDL Error: %s\n"
,path.c_str( ) ,SDL_GetError() );}SDL_FreeSurface (fOcgkfg); }return j9Nx9
;} void S_mLF(int VTo9JD,int jQ2Fj_ , vector<d55aA>&ttV0 ,bool M4DywQ){
 const d55aA FPpZ={-5,-5} ;d55aA&IWAa=jmXmtHT( eJnTG6koC ,VTo9JD,jQ2Fj_
 ); d55aA&cGUcm0ykRxK=jmXmtHT ( ttV0,VTo9JD,jQ2Fj_);d55aA cQkdE,NTWT;if
(jQ2Fj_==0 ){cQkdE =FPpZ;}else{ cQkdE=jmXmtHT(ttV0 ,VTo9JD,jQ2Fj_-1) ;}
if (M4DywQ ){if(VTo9JD== muE_-1){NTWT=FPpZ;} else{ NTWT=jmXmtHT(ttV0,VTo9JD
+1, jQ2Fj_);}} else{if(VTo9JD== 0){NTWT=FPpZ; }else{NTWT=jmXmtHT (ttV0,
VTo9JD-1,jQ2Fj_) ;}} cGUcm0ykRxK.jQ2Fj_=(IWAa.VTo9JD+IWAa.jQ2Fj_ +NTWT.
VTo9JD+cQkdE.jQ2Fj_-cQkdE.VTo9JD+NTWT.jQ2Fj_) /2;cGUcm0ykRxK.VTo9JD= ( IWAa
.VTo9JD-IWAa.jQ2Fj_-NTWT .VTo9JD+cQkdE. jQ2Fj_ +cQkdE.VTo9JD +NTWT.jQ2Fj_
)/2;float Tpuz =sqrt( cGUcm0ykRxK.VTo9JD*cGUcm0ykRxK .VTo9JD+cGUcm0ykRxK
.jQ2Fj_*cGUcm0ykRxK.jQ2Fj_);if (Tpuz>10){ float XnLf =10/Tpuz; cGUcm0ykRxK
.VTo9JD*= XnLf ;cGUcm0ykRxK.jQ2Fj_*=XnLf; }}void XFva( int lM0c){SDL_SetRenderDrawColor
(ofJi,0xFF,0xFF,0xFF,0xFF);SDL_RenderClear( ofJi);qWyVk.clear();for(int
 S9cm1=lM0c;S9cm1;S9cm1--){ int rsnZ=B73S(muE_);int VSEq=B73S(eexsl ) ;
scTR(rsnZ,VSEq , 100);}for(auto&ZcPi:qWyVk){ ut3uD4I(ZcPi.VTo9JD,ZcPi.jQ2Fj_
, 0xC0, 0x40, 0x40,1 ,-1, true) ;ut3uD4I(ZcPi. VTo9JD, ZcPi.jQ2Fj_, 0xFF
 ,0xC0, 0x80,0.3,-1,false);}SDL_SetRenderDrawColor (ofJi,0x00,0x00 ,0x00
,0xFF ); }void nWghwKh8_(){vector <d55aA>qglLUBa2Q8y,n4AtZ;sKaJ (qglLUBa2Q8y
);sKaJ( n4AtZ);for( int VTo9JD =0; VTo9JD <muE_;VTo9JD++) {for(int jQ2Fj_
=0;jQ2Fj_<eexsl;jQ2Fj_++) {S_mLF(VTo9JD,jQ2Fj_,qglLUBa2Q8y , false) ;}}
for( int jQ2Fj_= 0 ;jQ2Fj_<eexsl;jQ2Fj_++){for(int VTo9JD=0;VTo9JD<muE_
;VTo9JD++){S_mLF(VTo9JD, jQ2Fj_,n4AtZ, true);}} for(int VTo9JD=0 ;VTo9JD
 < muE_; VTo9JD++){ for(int jQ2Fj_=0;jQ2Fj_ <eexsl ;jQ2Fj_++){d55aA&cGUcm0ykRxK
=jmXmtHT(WceZ,VTo9JD,jQ2Fj_);cGUcm0ykRxK.VTo9JD =jmXmtHT( n4AtZ,VTo9JD,
jQ2Fj_).VTo9JD+jmXmtHT ( n4AtZ,VTo9JD,jQ2Fj_).VTo9JD;cGUcm0ykRxK . jQ2Fj_
=jmXmtHT(n4AtZ ,VTo9JD ,jQ2Fj_). jQ2Fj_ +jmXmtHT(n4AtZ,VTo9JD ,jQ2Fj_).
jQ2Fj_;}}}int main(int V15tvj,char*rfzzz0N[] ){srandom(time(0));sKaJ (eJnTG6koC
);sKaJ(WceZ); Ubqt::qawV IWAa(time(0) +3145) ;Ubqt::qawV cGUcm0ykRxK(time
(0 )+7350);int RJbL=0;int lM0c=nLaD8Go*nLaD8Go / 600;bool UE0W=false;for
(int VTo9JD=0;VTo9JD <muE_ ; VTo9JD++){for(int jQ2Fj_= 0 ;jQ2Fj_ <eexsl
; jQ2Fj_ ++){float SHSpK9w=AvQz,xNYT=1.0f;while(SHSpK9w >4){jmXmtHT (eJnTG6koC
,VTo9JD, jQ2Fj_). VTo9JD+= (IWAa.S2qp ( float(VTo9JD)/SHSpK9w ,float(jQ2Fj_
)/SHSpK9w,0)*SHSpK9w*2-SHSpK9w)* xNYT;jmXmtHT(eJnTG6koC,VTo9JD,jQ2Fj_) .
jQ2Fj_+=(cGUcm0ykRxK. S2qp (float(VTo9JD) /SHSpK9w,float(jQ2Fj_)/SHSpK9w
,0)* SHSpK9w *2 -SHSpK9w) * xNYT;SHSpK9w/=2;xNYT*=0.7;}}}nWghwKh8_ ();if
(!coEcs()){printf("Failed to initialize!\n");}else{if ( !Rnest ()){printf
("Failed to load media!\n");}else{bool zAy1 =false;SDL_Event H0hd ;if(oGtM
){ GATb( RJbL);RJbL++ ;} while(!zAy1){while(SDL_PollEvent(&H0hd)!=0){if
(H0hd. type==SDL_QUIT) {GATb (0);zAy1 =true ;}}if(!UE0W ||oGtM){XFva(lM0c
) ;UE0W= true;}SDL_RenderPresent (ofJi);SDL_Delay(100);}}} gZRf();return
 0;}