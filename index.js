import * as THREE from 'https://unpkg.com/three@0.153.0/build/three.module.js';
import { GLTFLoader } from '/loaders/GLTFLoader.js';

let scene, camera, renderer, model;

function init() {
    // Scene setup
    scene = new THREE.Scene();
    camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
    camera.position.set(0, 1, 2);

    // Renderer setup
    renderer = new THREE.WebGLRenderer({ antialias: true });
    renderer.setSize(window.innerWidth, window.innerHeight);
    document.body.appendChild(renderer.domElement);

    // Add light
    const ambientLight = new THREE.AmbientLight(0xffffff, 0.5);
    scene.add(ambientLight);
    const directionalLight = new THREE.DirectionalLight(0xffffff, 1);
    directionalLight.position.set(0, 10, 10);
    scene.add(directionalLight);

    // Load model
    const loader = new GLTFLoader();
    loader.load(
        '/models/MaterialsVariantsShoe.gltf',
        (gltf) => {
            model = gltf.scene;
            scene.add(model);
            animate();
        },
        undefined,
        (error) => {
            console.error('An error happened while loading the model:', error);
        }
    );

    // Resize handling
    window.addEventListener('resize', onWindowResize, false);
}

function onWindowResize() {
    camera.aspect = window.innerWidth / window.innerHeight;
    camera.updateProjectionMatrix();
    renderer.setSize(window.innerWidth, window.innerHeight);
}

function animate() {
    requestAnimationFrame(animate);
    if (model) model.rotation.y += 0.01;
    renderer.render(scene, camera);
}

init();
