alert("HOLAA")
let array = ["hola",2,true, [1,2,3],{}]
var vector = ["uno",34,"tres",564]

var [s1,s,s3,s4]=vector //s1="hola"....}
vector.push("cinco") //PUSH AGREGA UN ELEMENTO
vector.pop() //QUITA ULTIMO VALOR
vector.unshift("nuevo") //AGREGA AL inicio
vector.shift() //quita el primer elemento
vector.splice(2,0,"element1","element2") //agrega en la posicion2(3ro) "element1","element2"
vector.splice(3,1) // quita eleemento de la posic3(4to)
vector.splice(4,1,"sapo1","sapo2")//quita la posic4 y reemplaza con "sapo1","sapo2"
var extrae =vector.slice(2,4) //extrae desde la posicion 2 hasta 3(4-1)
//var extrae =vector.slice(m,n)  extrae desde la posicion m hasta (n-1)
var arra='HELLO MOTHER'.split('')// separa informacion y la convierte en cadena
arra.join('') // junta de array a cadena
// vector3.join(',')//convierte  a cadena separada por comas
v// ector3.join('A')convierte  a cadena separada por A
arra.reverse() // invierte un array
var vector2=["j","a","f","z"]
vector2.sort()// ordena de menor a mayor elorden de las letras
var vector3=[1000,45,5,85,700,2,500]
vector3.sort((a,b)=>a-b)//ordena de menor a mayor
vector3.sort((a,b)=>b-a)//ordena de mayor a  menor
vector3.concat([4,5,6])// concatena demas valores a los existentes --->crea un nuevo array y conserva vector3
vector3.indexOf(45)// posicion donde esta el primer cuarentaycinco
var v = vector3.concat([85,5,6,85])
v.find( namber => namber>100)// devuelve primer valor mayor que 100
v.findIndex( namber => namber>100) // devuelve el orden primer valor mayor que 100

var a= new Set(v) //elimina elementos repetidos y crea una  objeto de los elementos que quedan
 var aa=[...new Set(a)] // el objeto "a" lo transforma a array
var remove = arr => [...new Set(arr)]// funcion que elimina dato y genera un array defrente
Math.min(6,5,2,4,5,90)// da 2
Math.min(...v) //obtiene el minimo de un array
Math.max(...v) //obtiene el maximo de un array


//{var ii=0;while(ii<v.length){console.log(v[ii]);ii++;}}//recorre el array v
 for(var elemento of v) {console.log(elemento)}// recorre el array v
 var teachers = ["Yossy","Roger","Rolando","David"];
 teachers.some(el => el ==="Roger")//Devuelve true porque busca uno igual a "Roger"<
 teachers.some(el => el ==="Maria")//Devuelve flase porque busca igual a "Maria"
teachers.some(el => el.includes("a")) //true al menos tienen la letra a
teachers.every(el => el.includes("a"))// false todos deberian tener la a
teachers.every(el => el.length > 2) //true todos tienen mas de dos letras
