

function getLetter(s) {
    var v = new RegExp("[aoiue]");
    var a1 = new RegExp("[bcdfg]");
    var a2 = new RegExp("[hjklm]");
    var a3 = new RegExp("[npqrstvwxyz]")
    if (v.test(s[0]))
        return "A";
    if (a1.test(s[0]))
        return "B";
    if (a2.test(s[0]))
        return "C";
    if (a3.test(s[0]))
        return "D";
}

