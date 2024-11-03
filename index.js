import * as THREE from 'https://unpkg.com/three@0.153.0/build/three.module.js';


import { GLTFLoader } from 'https://unpkg.com/three@0.153.0/examples/jsm/loaders/GLTFLoader.js';

const loader = new GLTFLoader();

loader.load(
	// resource URL
	'dist\robot.gltf',
	// called when the resource is loaded
	function ( gltf ) {

		scene.add( gltf.scene );

		gltf.animations; // Array<THREE.AnimationClip>
		gltf.scene; // THREE.Group
		gltf.scenes; // Array<THREE.Group>
		gltf.cameras; // Array<THREE.Camera>
		gltf.asset; // Object

	},
	// called while loading is progressing
	function ( xhr ) {

		console.log( ( xhr.loaded / xhr.total * 100 ) + '% loaded' );

	},
	// called when loading has errors
	function ( error ) {

		console.log( 'An error happened' );

	}
);