<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Alef Lorenzo | Desenvolvedor</title>
    <style>
        :root {
            --primary: #2563eb;
            --primary-dark: #1d4ed8;
            --secondary: #4f46e5;
            --accent: #7c3aed;
            --text: #1f2937;
            --text-light: #6b7280;
            --bg: #f8fafc;
            --card-bg: #ffffff;
            --shadow: rgba(0, 0, 0, 0.1);
        }

        .dark-mode {
            --primary: #3b82f6;
            --primary-dark: #2563eb;
            --secondary: #6366f1;
            --accent: #8b5cf6;
            --text: #f3f4f6;
            --text-light: #d1d5db;
            --bg: #111827;
            --card-bg: #1f2937;
            --shadow: rgba(0, 0, 0, 0.25);
        }

        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            transition: background-color 0.3s, color 0.3s;
        }

        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            background-color: var(--bg);
            color: var(--text);
            line-height: 1.6;
        }

        .container {
            max-width: 1200px;
            margin: 0 auto;
            padding: 0 20px;
        }

        header {
            padding: 60px 0 40px;
            text-align: center;
            position: relative;
        }

        .theme-toggle {
            position: absolute;
            top: 20px;
            right: 20px;
            background: none;
            border: none;
            cursor: pointer;
            font-size: 24px;
            color: var(--text);
        }

        .profile-img {
            width: 150px;
            height: 150px;
            border-radius: 50%;
            object-fit: cover;
            border: 4px solid var(--primary);
            margin-bottom: 20px;
            box-shadow: 0 8px 16px var(--shadow);
        }

        h1 {
            font-size: 2.8rem;
            margin-bottom: 10px;
            color: var(--primary);
        }

        .tagline {
            font-size: 1.4rem;
            color: var(--text-light);
            margin-bottom: 20px;
        }

        .bio {
            max-width: 700px;
            margin: 0 auto 30px;
            font-size: 1.1rem;
        }

        .social-links {
            display: flex;
            justify-content: center;
            gap: 15px;
            margin: 20px 0;
        }

        .social-link {
            display: inline-flex;
            align-items: center;
            justify-content: center;
            width: 50px;
            height: 50px;
            border-radius: 50%;
            background-color: var(--primary);
            color: white;
            font-size: 1.5rem;
            text-decoration: none;
            transition: transform 0.3s, background-color 0.3s;
        }

        .social-link:hover {
            transform: translateY(-5px);
            background-color: var(--primary-dark);
        }

        .section {
            padding: 50px 0;
        }

        .section-title {
            text-align: center;
            margin-bottom: 40px;
            color: var(--primary);
            font-size: 2.2rem;
        }

        .skills-container {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
            gap: 25px;
        }

        .skill-category {
            background-color: var(--card-bg);
            border-radius: 12px;
            padding: 25px;
            box-shadow: 0 5px 15px var(--shadow);
        }

        .skill-category h3 {
            color: var(--primary);
            margin-bottom: 20px;
            font-size: 1.5rem;
            display: flex;
            align-items: center;
            gap: 10px;
        }

        .skill-items {
            display: flex;
            flex-wrap: wrap;
            gap: 12px;
        }

        .skill-item {
            background-color: var(--primary);
            color: white;
            padding: 8px 16px;
            border-radius: 20px;
            font-size: 0.9rem;
            display: inline-block;
        }

        .skill-item.intermediate {
            background-color: var(--secondary);
        }

        .skill-item.learning {
            background-color: var(--accent);
        }

        .projects-grid {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
            gap: 25px;
        }

        .project-card {
            background-color: var(--card-bg);
            border-radius: 12px;
            overflow: hidden;
            box-shadow: 0 5px 15px var(--shadow);
        }

        .project-img {
            width: 100%;
            height: 180px;
            object-fit: cover;
        }

        .project-content {
            padding: 20px;
        }

        .project-title {
            color: var(--primary);
            margin-bottom: 10px;
            font-size: 1.3rem;
        }

        .project-description {
            color: var(--text-light);
            margin-bottom: 15px;
            font-size: 0.95rem;
        }

        .project-tech {
            display: flex;
            flex-wrap: wrap;
            gap: 8px;
            margin-bottom: 15px;
        }

        .tech-tag {
            background-color: var(--primary);
            color: white;
            padding: 4px 10px;
            border-radius: 12px;
            font-size: 0.8rem;
        }

        .project-link {
            display: inline-block;
            color: var(--primary);
            text-decoration: none;
            font-weight: 600;
            font-size: 0.9rem;
        }

        .project-link:hover {
            text-decoration: underline;
        }

        .stats-container {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
            gap: 20px;
            text-align: center;
        }

        .stat-card {
            background-color: var(--card-bg);
            border-radius: 12px;
            padding: 25px;
            box-shadow: 0 5px 15px var(--shadow);
        }

        .stat-number {
            font-size: 2.5rem;
            font-weight: 700;
            color: var(--primary);
            margin-bottom: 10px;
        }

        .stat-label {
            color: var(--text-light);
            font-size: 1rem;
        }

        footer {
            text-align: center;
            padding: 40px 0;
            margin-top: 40px;
            color: var(--text-light);
            border-top: 1px solid var(--shadow);
        }

        @media (max-width: 768px) {
            h1 {
                font-size: 2.2rem;
            }
            
            .tagline {
                font-size: 1.2rem;
            }
            
            .skills-container,
            .projects-grid,
            .stats-container {
                grid-template-columns: 1fr;
            }
        }
    </style>
</head>
<body>
    <header>
        <button class="theme-toggle" id="themeToggle">🌙</button>
        <div class="container">
            <!-- Substitua pela URL da sua imagem -->
            <img src="https://images.unsplash.com/photo-1507003211169-0a1dd7228f2d?ixlib=rb-4.0.3&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1287&q=80" alt="Alef Lorenzo" class="profile-img">
            <h1>Alef Lorenzo</h1>
            <p class="tagline">Desenvolvedor Front-end & Entusiasta de Tecnologia</p>
            <p class="bio">
                Olá! Sou um apaixonado por tecnologia com foco em desenvolvimento Front-end. 
                Atualmente, estou me aprofundando em JavaScript moderno, React e outras tecnologias web, 
                enquanto também desenvolvo habilidades em C, C++ e Java. Adoro transformar ideias em 
                soluções digitais funcionais e esteticamente agradáveis.
            </p>
            <div class="social-links">
                <a href="#" class="social-link">📁</a>
                <a href="#" class="social-link">💼</a>
                <a href="#" class="social-link">📷</a>
                <a href="#" class="social-link">📧</a>
            </div>
        </div>
    </header>

    <section class="section">
        <div class="container">
            <h2 class="section-title">Habilidades Técnicas</h2>
            <div class="skills-container">
                <div class="skill-category">
                    <h3>🖥️ Front-end</h3>
                    <div class="skill-items">
                        <span class="skill-item intermediate">HTML5</span>
                        <span class="skill-item intermediate">CSS3</span>
                        <span class="skill-item intermediate">JavaScript</span>
                        <span class="skill-item">React</span>
                        <span class="skill-item">Bootstrap</span>
                    </div>
                </div>
                
                <div class="skill-category">
                    <h3>🔌 Linguagens de Programação</h3>
                    <div class="skill-items">
                        <span class="skill-item">C</span>
                        <span class="skill-item">C++</span>
                        <span class="skill-item">Java</span>
                        <span class="skill-item learning">Python</span>
                    </div>
                </div>
                
                <div class="skill-category">
                    <h3>🛠️ Ferramentas & Outros</h3>
                    <div class="skill-items">
                        <span class="skill-item">Git</span>
                        <span class="skill-item">GitHub</span>
                        <span class="skill-item">VS Code</span>
                        <span class="skill-item">Figma</span>
                    </div>
                </div>
            </div>
        </div>
    </section>

    <section class="section">
        <div class="container">
            <h2 class="section-title">Projetos em Destaque</h2>
            <div class="projects-grid">
                <div class="project-card">
                    <img src="https://images.unsplash.com/photo-1581276879432-15e50529f34b?ixlib=rb-4.0.3&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1170&q=80" alt="Projeto 1" class="project-img">
                    <div class="project-content">
                        <h3 class="project-title">Portfólio Pessoal</h3>
                        <p class="project-description">Site pessoal desenvolvido com HTML, CSS e JavaScript para showcase de projetos e habilidades.</p>
                        <div class="project-tech">
                            <span class="tech-tag">HTML</span>
                            <span class="tech-tag">CSS</span>
                            <span class="tech-tag">JavaScript</span>
                        </div>
                        <a href="#" class="project-link">Ver Projeto →</a>
                    </div>
                </div>
                
                <div class="project-card">
                    <img src="https://images.unsplash.com/photo-1551650975-87deedd944c3?ixlib=rb-4.0.3&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1074&q=80" alt="Projeto 2" class="project-img">
                    <div class="project-content">
                        <h3 class="project-title">E-commerce Responsivo</h3>
                        <p class="project-description">Loja virtual responsiva com carrinho de compras, desenvolvida com React e Bootstrap.</p>
                        <div class="project-tech">
                            <span class="tech-tag">React</span>
                            <span class="tech-tag">Bootstrap</span>
                            <span class="tech-tag">JavaScript</span>
                        </div>
                        <a href="#" class="project-link">Ver Projeto →</a>
                    </div>
                </div>
                
                <div class="project-card">
                    <img src="https://images.unsplash.com/photo-1550439062-609e1531270e?ixlib=rb-4.0.3&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1170&q=80" alt="Projeto 3" class="project-img">
                    <div class="project-content">
                        <h3 class="project-title">Sistema de Tarefas</h3>
                        <p class="project-description">Aplicação para gerenciamento de tarefas com funcionalidades de CRUD, desenvolvida em Java.</p>
                        <div class="project-tech">
                            <span class="tech-tag">Java</span>
                            <span class="tech-tag">Swing</span>
                            <span class="tech-tag">MySQL</span>
                        </div>
                        <a href="#" class="project-link">Ver Projeto →</a>
                    </div>
                </div>
            </div>
        </div>
    </section>

    <section class="section">
        <div class="container">
            <h2 class="section-title">Estatísticas do GitHub</h2>
            <div class="stats-container">
                <div class="stat-card">
                    <div class="stat-number">24</div>
                    <div class="stat-label">Repositórios</div>
                </div>
                <div class="stat-card">
                    <div class="stat-number">134</div>
                    <div class="stat-label">Commits</div>
                </div>
                <div class="stat-card">
                    <div class="stat-number">18</div>
                    <div class="stat-label">Seguidores</div>
                </div>
                <div class="stat-card">
                    <div class="stat-number">7</div>
                    <div class="stat-label">Projetos Destacados</div>
                </div>
            </div>
        </div>
    </section>

    <footer>
        <div class="container">
            <p>© 2023 Alef Lorenzo. Todos os direitos reservados.</p>
            <p>Desenvolvido com ❤️ e ☕</p>
        </div>
    </footer>

    <script>
        // Toggle de tema claro/escuro
        const themeToggle = document.getElementById('themeToggle');
        themeToggle.addEventListener('click', () => {
            document.body.classList.toggle('dark-mode');
            themeToggle.textContent = document.body.classList.contains('dark-mode') ? '☀️' : '🌙';
        });

        // Animação simples para os elementos ao rolar
        document.addEventListener('DOMContentLoaded', function() {
            const animateOnScroll = function(elements) {
                elements.forEach(element => {
                    const elementPosition = element.getBoundingClientRect().top;
                    const screenPosition = window.innerHeight / 1.3;
                    
                    if(elementPosition < screenPosition) {
                        element.style.opacity = 1;
                        element.style.transform = 'translateY(0)';
                    }
                });
            };
            
            const animatedElements = document.querySelectorAll('.skill-category, .project-card, .stat-card');
            animatedElements.forEach(element => {
                element.style.opacity = 0;
                element.style.transform = 'translateY(20px)';
                element.style.transition = 'opacity 0.5s ease, transform 0.5s ease';
            });
            
            window.addEventListener('scroll', () => {
                animateOnScroll(animatedElements);
            });
            
            // Disparar uma vez ao carregar a página
            animateOnScroll(animatedElements);
        });
    </script>
</body>
</html>
