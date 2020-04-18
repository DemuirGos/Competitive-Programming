

/*
 * Complete the reverseString function
 * Use console.log() to print to stdout.
 */
function reverseString(s) {
    try{
        var r=s.split("");
        r.reverse();
        console.log(r.join(""));
    }
    catch(e){
        console.log(e.message);
        console.log(s);
    }
}

