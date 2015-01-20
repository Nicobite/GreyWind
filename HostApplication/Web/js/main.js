/* #DEFINES :'( */

var FACTOR = 0.95;


/* GLOBAL VARIABLES */

var object;
var scene, camera, renderer;
var geometry, material, mesh;
var initX, initY;
var diffX, diffY;
var controls;

var ROOMSIZE_X = 800;
var ROOMSIZE_Y = 800;
var ROOMFLOOR = -200;


/* MAIN */

init();
trackball();
animate();

/* USEFUL FUNCTIONS */

/**
	Creates a scene, a camera, draws a mesh
*/
function init() {
	object = new THREE.Object3D();
	scene = new THREE.Scene();
	camera = new THREE.PerspectiveCamera( 75, window.innerWidth / window.innerHeight, 1, 10000 );
	camera.position.z = 1000;
	scene.add( object );
	
	renderer = new THREE.CanvasRenderer();
	renderer.setSize( window.innerWidth * FACTOR, window.innerHeight * FACTOR );
	document.body.appendChild( renderer.domElement );
	
	object.add( drawOrigin() 	);
	object.add( drawRoom() 		);
	//object.add( drawPyramid(0,0,0,"rgb(100,225,225)")	);
	
	cppCom.objToJS.connect(cppSlot);
	
}

/**

*/
function cppSlot(type,x,y,z){
	switch(type) {
		case "face":
		    object.add( drawCube(x,y,z,"rgb(255,120,120)") );
		    break;
		case "pyr":
		    object.add( drawPyramid(x,y,z,"rgb(100,225,225)") );
		    break;
		case "b":
		    object.add( drawCube(x,y,z,"rgb(255,240,55)") );
		    break;
		default:
		    object.add( drawCube(x,y,z,"rgb(140,140,140)") );
	}
}

/**
	Draws a cube
*/
function drawCube(x,y,z,color1){
	var geometry2 = new THREE.BoxGeometry( 60, 60, 60 );
	var material2 = new THREE.MeshBasicMaterial( { color: color1, wireframe: false } );
	var mesh2 = new THREE.Mesh( geometry2, material2 );
	mesh2.position.x = x;
	mesh2.position.y = y;
	mesh2.position.z = z;
	return mesh2;
}

/**
	Draws the simplest representation of a room
*/
function drawRoom(){
	var geometry2 = new THREE.Geometry();
	// Four vertices as the angles of the room
	var v1 = new THREE.Vector3(ROOMSIZE_X	,	 ROOMSIZE_Y	,	ROOMFLOOR);
	var v2 = new THREE.Vector3(ROOMSIZE_X	,	-ROOMSIZE_Y	,	ROOMFLOOR);
	var v3 = new THREE.Vector3(-ROOMSIZE_X	,	-ROOMSIZE_Y	,	ROOMFLOOR);
	var v4 = new THREE.Vector3(-ROOMSIZE_X	,	ROOMSIZE_Y	,	ROOMFLOOR);
	geometry2.vertices.push(v1);
	geometry2.vertices.push(v2);
	geometry2.vertices.push(v3);
	geometry2.vertices.push(v4);
	geometry2.vertices.push(v1);
	geometry2.vertices.push(v3);
	geometry2.vertices.push(v2);
	geometry2.vertices.push(v4);
	// Creating material
	var material2 = new THREE.LineBasicMaterial({color: 0x000000,linewidth: 1});
	var line = new THREE.Line(geometry2, material2);
	line.position.x = 0;
	line.position.y = 0;
	line.position.z = ROOMFLOOR;
	return line;
}

function drawOrigin(){
	var geometry = new THREE.Geometry();
	var v1 = new THREE.Vector3(0,0,	+2*ROOMFLOOR);
	var v2 = new THREE.Vector3(0,0,	-2*ROOMFLOOR);
	geometry.vertices.push(v1);
	geometry.vertices.push(v2);
	var material = new THREE.LineBasicMaterial({color: "rgb(50,50,50)",linewidth: 1});
	var line = new THREE.Line(geometry, material);
	line.position.x = 0;
	line.position.y = 0;
	line.position.z = 0;
	return line;
}


///////////////////////
function drawPyramid(x,y,z,color1){
	var pyramidGeometry = new THREE.CylinderGeometry(0, 60, 80, 4, 1, false); 
	var material2 = new THREE.MeshBasicMaterial( { color: color1, wireframe: false } );
	var pyramidMesh = new THREE.Mesh( pyramidGeometry, material2 );
	pyramidMesh.position.x = x;
	pyramidMesh.position.y = y;
	pyramidMesh.position.z = z;
	pyramidMesh.rotation.x = Math.PI/2;
	return pyramidMesh;
	
}
///////////////////////


/**
	Renders the scene from the PoV of the camera
*/
function animate() {
	// note: three.js includes requestAnimationFrame shim
	requestAnimationFrame( animate );
	//*
	if (!controls) {
		alert('no controls found');
	}
	else {
		controls.update();
	}//*/
	//mesh.rotation.x += 0.01;
	//mesh.rotation.y += 0.02;
	renderer.render( scene, camera );
}

/**
	Uses the TrackballControls JS script in order to move the camera around
		LMB: Rotate around the centre of scene
		RMB: Pan around the plane containing the camera
		MMB: Zoom
	However, FOV effects after Pan are complete trash.
*/
function trackball(){
	/*Creating trackball type mouse control variable*/
	controls = new THREE.TrackballControls( camera );
	
	/*Tweaking action speeds*/
	controls.rotateSpeed = 4.0;
	controls.zoomSpeed = 4.0;
	controls.panSpeed = 3.0;
	
	/*Tweaking authorized actions*/
	controls.noZoom = false;
	controls.noPan = false;
	
	/*staticMoving at false makes moving the scene A PAIN*/
	controls.staticMoving = true;
	
	/*Unknown, found on website*/
	//controls.dynamicDampingFactor = 28;
	//controls.keys = [ 65, 83, 68 ];
	//controls.addEventListener( 'change', render );
}


/* USEFUL FUNCTIONS/others */

function onMouseClick(event){
}

function onMouseDown(event){
}

function onMouseUp(event){
}
