let strongPasswordChecker = function (password) {

    let numberOfSteps = 0;
    if (passwordHasAppropriateLength(password)) {
        numberOfSteps += passwordContainsConsecutiveCharacters(password)
        numberOfSteps += charactersToAddOrRemove(password);
    } else {
        if(password.length<3){
            numberOfSteps+=charactersToAddOrRemove(password)
        }
    }

    console.log("🚀 ~ file: pw.js ~ line 14 ~ numberOfSteps", numberOfSteps)
    return numberOfSteps;
};

function charactersToAddOrRemove(password) {
    if (password.length > 20) {
        return password.length - 20;
    } else if (password.length < 6) {
        return 6 - password.length;
    } else return 0;
}

function passwordHasAppropriateLength(password) {
    return password.length >= 6 && password.length <= 20
}

function passwordContainsRequiredCharacters(password) {
    let containsLowercaseLetter = false;
    let containsUppercaseLetter = false;
    let containsNumber = false;

    for (let i = 0; i < password.length; i++) {
        if (password.charCodeAt(i) >= 65 && password.charCodeAt(i) <= 90) {
            containsUppercaseLetter = true;
        } else if (password.charCodeAt(i) >= 97 && password.charCodeAt(i) <= 122) {
            containsLowercaseLetter = true;
        } else if (password.charCodeAt(i) >= 48 && password.charCodeAt(i) <= 57) {
            containsNumber = true;
        }
    }
    return containsUppercaseLetter && containsLowercaseLetter && containsNumber;
}

function passwordContainsConsecutiveCharacters(password) {
    let counter = 1;
    let consecutiveCharacters = []
    for (let i = 1; i < password.length; i++) {
        if (password[i] === password[i - 1]) {
            counter++;
            if (counter >= 3) {
                consecutiveCharacters.push(password[i])
            }
        } else {
            counter = 1;
        }
    }
    return consecutiveCharacters.length;
}

strongPasswordChecker("lee")



// /**
//  * @param {string} password
//  * @return {number}
//  */
//  var strongPasswordChecker = function(password) {
//     let numberOfSteps = 0;

//   if(password.length<=6){
//       if(passwordContainsConsecutiveCharacters(password)){
//           numberOfSteps++;
//       }
//       numberOfSteps+=passwordHasAppropriateLength(password);
//   } else {
//       if(!passwordContainsRequiredCharacters(password)){
//           numberOfSteps++;
//       }
//       numberOfSteps+=passwordHasAppropriateLength(password);
//   }
//      return numberOfSteps;
//   };


// function passwordHasAppropriateLength(password){
//   return password.length>=6 ? 0 : 6 - password.length;
// }

// function passwordContainsRequiredCharacters(password){
//   let containsLowercaseLetter=false;
//   let containsUppercaseLetter=false;
//   let containsNumber=false;

//   for(let i=0;i<password.length;i++){
//      if(password.charCodeAt(i)>=65 && password.charCodeAt(i)<=90){
//          containsUppercaseLetter=true;
//      } else  if(password.charCodeAt(i)>=97 && password.charCodeAt(i)<=122){
//          containsLowercaseLetter=true;
//      } else  if(password.charCodeAt(i)>=48 && password.charCodeAt(i)<=57){
//          containsNumber=true;
//      }
//   }
//   return containsUppercaseLetter && containsLowercaseLetter && containsNumber;
// }

// function passwordContainsConsecutiveCharacters(password){
//   let counter = 1;
//   let passwordHasConsecutiveCharacters = false;

//   for (let i = 1; i < password.length; i++) {
//       if (password[i] === password[i - 1]) {
//           counter++;
//           if (counter >= 3) {
//               passwordHasConsecutiveCharacters = true;
//           }
//       } else {
//           counter = 1;
//       }
//   }
//   return passwordHasConsecutiveCharacters;
// }