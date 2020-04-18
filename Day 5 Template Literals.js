

/*
 * Determine the original side lengths and return an array:
 * - The first element is the length of the shorter side
 * - The second element is the length of the longer side
 * 
 * Parameter(s):
 * literals: The tagged template literal's array of strings.
 * expressions: The tagged template literal's array of expression values (i.e., [area, perimeter]).
 */
function sides(literals, ...expr) {
    var s_1=(expr[1]+Math.sqrt(expr[1]*expr[1]-16*expr[0]))/4;
    var s_2=(expr[1]-Math.sqrt(expr[1]*expr[1]-16*expr[0]))/4;
    return [s_1,s_2].sort();
}

