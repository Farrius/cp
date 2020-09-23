#include <bits/stdc++.h>
using namespace std;
int n,ans,sr,res=100000000,rr,s;
struct p{int l,r;}a[100010];
int cmp(p x,p y){return x.l<y.l;}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].l,&a[i].r);
         sort (a + 1, a + n + 1, cmp); // Sort by the left endpoint
    for(int i=1;i<=n;i++)if(a[i].r>sr)rr=max(sr,a[i].l),ans+=a[i].r-rr,sr=a[i].r;
         // If the end point of the cover is smaller than the original recording current operating point of the end, covering the length of the new segment is added and updates the segment end cover
	 //
	cout << ans << '\n';
    sr=0,a[n+1].l=a[n].r;
         // initialize and re-establish a boundary
    for(int i=1;i<=n;i++)
        if(a[i].r<=sr)res=0;
        else s=min(a[i+1].l,a[i].r)-max(a[i].l,sr),res=min(res,s),sr=max(a[i].r,sr);
                 // find the smallest period and shrinking Look
    res=max(0,res),printf("%d",ans-res);
    return 0;
}
