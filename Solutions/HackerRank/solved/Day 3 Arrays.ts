
function getSecondLargest(a) {
    a.sort((a,b)=>a-b);
    var max=a[a.length-1];
    for(let i=a.length-1;i>=0;i--){
        if(a[i]!=max){
            return a[i];
        }
    }
    return max;
}

