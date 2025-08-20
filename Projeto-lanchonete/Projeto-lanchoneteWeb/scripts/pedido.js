let carrinho = [];
let total = 0;

function adicionarItem(item, preco) {
  carrinho.push({ item, preco });
  total += preco;
  atualizarCarrinho();
}

function atualizarCarrinho() {
  const carrinhoEl = document.getElementById('carrinho');
  carrinhoEl.innerHTML = carrinho
    .map(({ item, preco }) => `<li>${item} - R$ ${preco.toFixed(2)}</li>`)
    .join('');
  document.getElementById('total').textContent = `Total: R$ ${total.toFixed(2)}`;
}

function finalizarPedido() {
  if (carrinho.length === 0) {
    alert('Seu carrinho está vazio!');
  } else {
    alert('Pedido finalizado com sucesso!');
    carrinho = [];
    total = 0;
    atualizarCarrinho();
  }
}
