/* #DEFINES :'( */

var FACTOR = 0.95;


/* GLOBAL VARIABLES */

var object;
var scene, camera, renderer;
var geometry, material, mesh;
var initX, initY;
var diffX, diffY;
var controls;

var ROOMSIZE_X = 550;
var ROOMSIZE_Y = 800;
var ROOMFLOOR = -200;


/* MAIN */

init();
trackball();
animate();
//document.addEventListener( 'mousedown', onMouseDown, false );
//document.addEventListener( 'mouseup', onMouseUp, false );
//document.addEventListener( 'click', onMouseClick, false );


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
	
	object.add( drawCube(0,0,0,0xf55000) );
	object.add( drawRoom() );
	
	/* The tricky part */
	cppCom.intToJS.connect(myInterestingScriptFunction);
	
	
	
	//object.add( drawCube(500,0,0,0x000000) );
	//object.add( drawCube(0,500,0,0x55f000) );
	//object.add( drawCube(0,0,-500,0xf55000) );
}

/**

*/
function myInterestingScriptFunction(i){
	object.add( drawCube(i,0,0,0x000000) );
	alert('TEST');
}

/**
	Draws a cube
*/
function drawCube(x,y,z,color1){
	var geometry2 = new THREE.BoxGeometry( 180, 180, 180 );
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
	// Creating a geometry around the origin
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
	// Creating material
	var material2 = new THREE.LineBasicMaterial({color: 0x000000,linewidth: 3});
	var line = new THREE.Line(geometry2, material2);
	line.position.x = 0;
	line.position.y = 0;
	line.position.z = ROOMFLOOR;
	return line;
}



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

/* Not by me but quite a good idea (Trackball is better) */	
/*function onDocumentMouseMove( event ) {
	alert('Mouse move detected');
	event.preventDefault();
	//alert('Mouse move detected')
	if ( isMouseDown ) {
		alert('You have clicked');
		theta = - ( ( event.clientX - onMouseDownPosition.x ) * 0.5 )
				+ onMouseDownTheta;
		phi = ( ( event.clientY - onMouseDownPosition.y ) * 0.5 )
				+ onMouseDownPhi;

		phi = Math.min( 180, Math.max( 0, phi ) );

		camera.position.x = radious * Math.sin( theta * Math.PI / 360 )
                            * Math.cos( phi * Math.PI / 360 );
		camera.position.y = radious * Math.sin( phi * Math.PI / 360 );
		camera.position.z = radious * Math.cos( theta * Math.PI / 360 )
                           * Math.cos( phi * Math.PI / 360 );
		camera.updateMatrix();
	}
	mouse3D = projector.unprojectVector(
		new THREE.Vector3(
			( event.clientX / renderer.domElement.width ) * 2 - 1,
			- ( event.clientY / renderer.domElement.height ) * 2 + 1,
			0.5
		),
		camera
	);
	ray.direction = mouse3D.subSelf( camera.position ).normalize();
	interact();
	render();
}//*/
