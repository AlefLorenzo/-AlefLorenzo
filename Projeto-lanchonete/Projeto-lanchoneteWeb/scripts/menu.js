// Dados do Menu
const menu = [
        { 
        id: 1, category: 'bebidas', name: 'Refrigerante', description: 'Latinha gelada de 350ml', price: 5.00, 
        image: 'assets/imagens/bebidas/refrigerante.jpg' 
        },
        { 
        id: 2, category: 'bebidas', name: 'Suco Natural', description: 'Copo de suco feito na hora', price: 7.00, 
        image: 'assets/imagens/bebidas/suco.jpg' 
        },
        { 
        id: 3, category: 'lanches', name: 'X-Burguer', description: 'Hambúrguer com queijo e molho especial', price: 12.99, 
        image: 'assets/imagens/lanches/xburguer.jpg' 
        },
        { 
        id: 4, category: 'lanches', name: 'X-Salada', description: 'Hambúrguer com salada e queijo', price: 14.99, 
        image: 'assets/imagens/lanches/xsalada.jpg' 
        },
        { 
        id: 5, category: 'sobremesas', name: 'Mousse de Chocolate', description: 'Delicioso mousse caseiro', price: 6.50, 
        image: 'assets/imagens/sobremesas/mousse.jpg' 
        },
        { 
        id: 6, category: 'sobremesas', name: 'Pudim', description: 'Clássico pudim de leite condensado', price: 8.00, 
        image: 'assets/imagens/sobremesas/pudim.jpg' 
        },
    ];
    
    // Referências ao DOM
    const menuContainer = document.getElementById('menu-items');
    const modal = document.getElementById('modal');
    const modalTitle = document.getElementById('modal-title');
    const modalImage = document.getElementById('modal-image');
    const modalDescription = document.getElementById('modal-description');
    const modalPrice = document.getElementById('modal-price');
    
    // Função para carregar o menu
    function loadMenu(category = 'all') {
        menuContainer.innerHTML = '';
    
        const filteredMenu = category === 'all' ? menu : menu.filter(item => item.category === category);
    
        filteredMenu.forEach(item => {
        const menuItem = document.createElement('div');
        menuItem.className = 'bg-white rounded-lg shadow-lg overflow-hidden';
    
        menuItem.innerHTML = `
            <img src="${item.image}" alt="${item.name}" class="w-full h-40 object-cover">
            <div class="p-4">
            <h3 class="text-lg font-semibold text-orange-700">${item.name}</h3>
            <p class="text-gray-600">${item.description}</p>
            <p class="text-orange-600 font-bold">R$ ${item.price.toFixed(2)}</p>
            <button onclick="showDetails(${item.id})" class="bg-orange-500 text-white px-4 py-2 mt-4 rounded-lg hover:bg-orange-600">
                Ver Detalhes
            </button>
            </div>
        `;
    
        menuContainer.appendChild(menuItem);
        });
    }
    
    // Filtrar Menu
    function filterMenu(category) {
        loadMenu(category);
    }
    
    // Exibir Modal
    function showDetails(id) {
        const item = menu.find(i => i.id === id);
        modalTitle.textContent = item.name;
        modalImage.src = item.image;
        modalDescription.textContent = item.description;
        modalPrice.textContent = `R$ ${item.price.toFixed(2)}`;
        modal.classList.remove('hidden');
    }
    
    // Fechar Modal
    function closeModal() {
        modal.classList.add('hidden');
    }
    
    // Carregar o menu ao iniciar
    loadMenu();
    