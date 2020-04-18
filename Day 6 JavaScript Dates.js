

// The days of the week are: 
let days=["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
function getDayName(dateString) {
    let d = new Date(dateString);
    return days[d.getDay()];
}

