pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                git 'https://github.com/OSoliman330/Hello_World_with_Jenkins.git'
            }
        }
        stage('Build') {
            steps {
                sh '''
                mkdir -p build
                cd build
                cmake ..
                cmake --build .
                '''
            }
        }
        stage('Run') {
            steps {
                sh '''
                cd build
                ./HelloWorld
                '''
            }
        }
    }
}