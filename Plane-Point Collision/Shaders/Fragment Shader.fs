#version 450 core
in vec4 fragColor;
in vec3 fragNormal;
in vec3 fragPos;

out vec4 color;

uniform float ambientStr = 0.3f;
uniform vec3 ambientColor = vec3(1.0f, 1.0f, 1.0f);
uniform vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);
uniform vec3 lightPos = vec3(700.0f, 700.0f, 1000.0f);
uniform float lightSpecStr = 1.0f;
uniform vec3 camPos;
uniform float shininess = 1.0f;

void main() {

    /*---------------------------------------*/
    /*|            PHONG SHADER             |*/
    /*---------------------------------------*/

    //AMBIENT COLOR
    vec3 ambient = ambientStr * ambientColor;
    // Light Direction
    vec3 norm = normalize(fragNormal);
    vec3 lightDir = normalize(fragPos - lightPos);
    // Diffuse Coloring
    float diffuseStr = max(dot(norm, -lightDir ), 0.0f);
    vec3 diffuse = diffuseStr * lightColor;

    // Specular Highlight
    vec3 negViewDir = normalize(camPos - fragPos);
    vec3 reflectDir = reflect(lightDir, norm);
    float spec = pow(max(dot(negViewDir , reflectDir), 0.0f), shininess);
    vec3 specular = lightSpecStr * spec * lightColor;

    color = vec4(ambient + diffuse + specular, 1.0f) * fragColor;
    
}

