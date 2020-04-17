//var nombre = "Manuel";
var x=44567457,y=7,z;
z=x+y;

let yy=342;//solo se usa en su entorno
const pi = 3.14;//no cambia

//let angel = `mi hermano es un demetrio pero esta aprendiedo  ${x} funciones`;//DECLARAR VARIABLE QUE VA CAMBEANDO --->${}

var nombre = `EDTean tiene ${yy} años`;
//alert("hoa angel "+ nombre);


let div = `
  <div class="container">
    ${nombre}
  </div>`;

  document.body.innerHTML = div;

var numbers = [1,2,3,4,5,6,7];
let data ={
  nombre: "alexis",
  apellido: "local",
  edad: 34,
}
console.log(data);
console.log(numbers);

//TIPO DE DATO  typeof  number string ...
console.log(typeof(numbers));
//arrays
var vector1=[1,2,3];
var vector2=vector1;
/*vector2
(3) [1, 2, 3]
vector1
(3) [1, 2, 3]*/
vector2.push(5);
/*
vector2
(4) [1, 2, 3, 5]
vector1
(4) [1, 2, 3, 5]*/

// OPERADORES
 // EDAD+=1; EDAD=EDAD+1
 // EDAD-=5; EDAD=EDAD-5
 // EDAD*=2; EDAD=EDAD*2
 // EDAD/=4; EDAD=EDAD/4

//comparacion
 // 5=="5"  true
 // 5===="5" false
 // 5!="5" false
 // 5!=="5" true
 // ! negacion   !0 true !1  false
 // typeof 5  -->"number"
 // % residuo
 /*
 OPERADOR TERNEARIO DE LOGICA
 var edad = prompt('dime tu edad')
 var mensaje = edad > 18
               ? 'erers mayor de edad'
               : 'eres aun un niñop'
  alert(mensaje)
 */

 // var d = a || 5  d->5  busca el primer verdadero
 // var d = a && 8  d=a   busca el primer falso

 // NUMEROS
 // var number =5,1234
 // number.toFixed(2)-->5,12 especifica el numero de decimales
 // parseInt("10")-->10 recibe string y convierte a NUMERO ENTERO
 // parseFloat("12,13") ---12,13 recibe cadena y convierte A numero racional
 // funcion Math
 // Math.floor(20,7)-->20
 // Math.ceil(20,7)-->21
 // Math.round(20,7)-->20
 // Math.round(20,7)-->20
 // Math.random()--> numero entre 0 y 1
 // Math.ceil(Math.random()*12) numero entre 1 y 12
 // numero de caractres "alexis".length --->6
 // Metodos  "  hola  ".trim()  --->"hola"   quita espacion en blanco
 // metodo   'hola'
 // pasar a mayuscula  manuel.toUpperCase() ---->MANUEL
 // Pasar a minuscula  MaNueL.toLowerCase()  ---->manuel
 // caracteres en que posicion está el caracter e?  "Manuel".indexOf('e') --->4
 // en que posicion esta la 3ra 'o'  "contalaoperi".indexOf('o',2)
 // encuentra el ultimo caracter"o" "hola amigo".lastIndexOf('o') -->9
 // preguntta si una cadena d etexto inicia con cadena starsWith()
 // pREGUNTA si una cadena termina con una cadena "fverer rgerger".endsWith('ger') --->true
 // MANIPULAR TEXTOS
 // EDTean javaScript desde cero manipular TEXTOS
 // if-->else
 // switch(){case1  break case 2: break --->default: break}
 // `` comilla especial

//OBJETOS
const c = console.log;
let multiplicar = (a,b) => a*b;
c(multiplicar(2,5));
var n=7
function sumarr(n){
  if(n==0){return 0}
  return n+sumarr(n-1)
}
console.log("hola");
console.log(sumarr(n));
console.log(n);
