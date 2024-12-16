#include<stdio.h>

#define WIDTH 101
#define HEIGHT 103


void solve(){
    int px,py,vx,vy;
    long a=0,b=0,c=0,d=0;
    while(scanf("p=%d,%d v=%d,%d\n",&px,&py,&vx,&vy)!=EOF){
        px = (px+ ((vx*100)%WIDTH + WIDTH)%WIDTH )%WIDTH;
        py = (py+ ((vy*100)%HEIGHT + HEIGHT)%HEIGHT )%HEIGHT;
        if(px<WIDTH/2 && py<HEIGHT/2)a++;
        if(px>WIDTH/2 && py<HEIGHT/2)b++;
        if(px<WIDTH/2 && py>HEIGHT/2)c++;
        if(px>WIDTH/2 && py>HEIGHT/2)d++;
    }
    
    printf("ans = %ld\n",a*b*c*d);
}

int main(){
    freopen("in.txt","r",stdin);
    solve();
}