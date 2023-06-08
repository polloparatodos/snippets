    //******************** Coffee Bag - Box ********************
    // Activate the VBOs contained within the mesh's VAO
    glBindVertexArray(meshes.gBoxMesh.vao);

    // 1. Scales the object
    scale = glm::scale(glm::vec3(3.5f, 1.75f, 2.5f));
    // 2. Rotate the object
    rotation = glm::rotate(-0.78f, glm::vec3(0.0, 1.0f, 0.0f));
    // 3. Position the object
    translation = glm::translate(glm::vec3(6.0f, 0.0f, -1.0f));
    // Model matrix: transformations are applied right-to-left order
    model = translation * rotation * scale;
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    // bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gTextureGlassId);

    glDrawElements(GL_TRIANGLES, meshes.gBoxMesh.nIndices, GL_UNSIGNED_INT, (void*)0);

    glBindTexture(GL_TEXTURE_2D, 0);
