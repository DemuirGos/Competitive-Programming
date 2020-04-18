

/*
 * Complete the vowelsAndConsonants function.
 * Print your output using 'console.log()'.
 */
function vowelsAndConsonants(s) {
    var a = [];
    var regex = new RegExp("[aoiueAOIUE]");
    for (var i = 0; i < s.length; i++) {
    if (regex.test(s[i])) {
        console.log(s[i]);
    }
    else {
        a.push(s[i]);
    }
    }
    for (var i = 0; i < a.length; i++)
    console.log(a[i]);
}

