function selectedA() {
    var selectA = document.getElementById("selectA");
    currentValue = selectA.value;
    for (i = 0; i < selectA.options.length; ++i) {
        if (selectA.options[i].value == currentValue) {
            selectA.options.remove(i);
            break;
        }
    }

    var newOption = document.createElement("option");
    newOption.text = currentValue;
    newOption.value = currentValue;
    document.getElementById("selectB").appendChild(newOption);
}

function selectedB() {
    var selectB = document.getElementById("selectB");
    currentValue = selectB.value;
    for (i = 0; i < selectB.options.length; ++i) {
        if (selectB.options[i].value == currentValue) {
            selectB.options.remove(i);
            break;
        }
    }

    var newOption = document.createElement("option");
    newOption.text = currentValue;
    newOption.value = currentValue;
    document.getElementById("selectA").appendChild(newOption);
}
