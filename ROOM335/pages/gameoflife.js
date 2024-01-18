
const canvas = document.getElementById("game-of-life");
const ctx = canvas.getContext("2d");

let grid = createRandomGrid(canvas.width, canvas.height);

window.addEventListener("resize", () => {
    canvas.width = window.innerWidth;
    canvas.height = window.innerHeight;
    grid = createRandomGrid(canvas.width, canvas.height); // Regenerate grid on resize
});

function createRandomGrid(width, height) {
    const grid = [];
    for (let y = 0; y < height; y++) {
        grid.push([]);
        for (let x = 0; x < width; x++) {
            grid[y][x] = Math.random() < 0.2; // Randomly initialize cells
        }
    }
    return grid;
}

function countNeighbors(grid, x, y) {
    let count = 0;
    for (let i = -1; i <= 1; i++) {
        for (let j = -1; j <= 1; j++) {
            if (!(i === 0 && j === 0) && grid[y + i]?.[x + j] === true) {
            count++;
            }
        }
    }
    return count;
}

function updateGrid(grid) {
    const newGrid = grid.map((row) => row.slice()); // Create a copy
    for (let y = 0; y < grid.length; y++) {
        for (let x = 0; x < grid[y].length; x++) {
            const neighbors = countNeighbors(grid, x, y);
            if (grid[y][x]) {
                newGrid[y][x] = neighbors === 2 || neighbors === 3; // Survival rules
            } else {
                newGrid[y][x] = neighbors === 3; // Birth rules
            }
        }
    }
    return newGrid;
}

function drawGrid(ctx, grid) {
    const cellSize = 10;
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    for (let y = 0; y < grid.length; y++) {
        for (let x = 0; x < grid[y].length; x++) {
            if (grid[y][x]) {
                ctx.fillStyle = "red";
                ctx.fillRect(x * cellSize, y * cellSize, cellSize, cellSize);
            }
        }
    }   
}

function animate() {
    grid = updateGrid(grid);
    drawGrid(ctx, grid);
    requestAnimationFrame(animate);
}

canvas.width = window.innerWidth;
canvas.height = window.innerHeight;
grid = createRandomGrid(canvas.width, canvas.height);
animate();