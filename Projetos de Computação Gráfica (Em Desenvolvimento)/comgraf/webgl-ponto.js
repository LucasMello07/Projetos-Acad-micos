// Obtém o elemento canvas
const canvas = document.getElementById('glcanvas');

// Obtém o contexto WebGL
const gl = canvas.getContext('webgl');

// Verifica se o contexto WebGL foi obtido com sucesso
if (!gl) {
    alert('Não foi possível obter o contexto WebGL');
}

// Define as coordenadas do ponto
const pointVertices = [
    0.0, 0.0, 0.0
];

// Cria um buffer para armazenar as coordenadas do ponto
const pointBuffer = gl.createBuffer();
gl.bindBuffer(gl.ARRAY_BUFFER, pointBuffer);
gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(pointVertices), gl.STATIC_DRAW);

// vertex shader
const vertexShaderSource = `
    attribute vec3 aPosition;
    void main() {
        gl_Position = vec4(aPosition, 1.0);
        gl_PointSize = 10.0;
    }
`;
const vertexShader = gl.createShader(gl.VERTEX_SHADER);
gl.shaderSource(vertexShader, vertexShaderSource);
gl.compileShader(vertexShader);

// Cria um shader de fragmento
const fragmentShaderSource = `
    void main() {
        gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
    }
`;
const fragmentShader = gl.createShader(gl.FRAGMENT_SHADER);
gl.shaderSource(fragmentShader, fragmentShaderSource);
gl.compileShader(fragmentShader);

// Cria um programa WebGL e anexa os shaders
const program = gl.createProgram();
gl.attachShader(program, vertexShader);
gl.attachShader(program, fragmentShader);
gl.linkProgram(program);
gl.useProgram(program);

// Obtém a localização do atributo aPosition
const aPositionLocation = gl.getAttribLocation(program, 'aPosition');
gl.enableVertexAttribArray(aPositionLocation);
gl.vertexAttribPointer(aPositionLocation, 3, gl.FLOAT, false, 0, 0);

// Limpa o canvas e renderiza o ponto vermelho
gl.clearColor(0.0, 0.0, 0.0, 1.0);
gl.clear(gl.COLOR_BUFFER_BIT);
gl.drawArrays(gl.POINTS, 0, 1);
